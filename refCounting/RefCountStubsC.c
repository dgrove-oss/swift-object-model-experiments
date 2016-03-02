#include <stdio.h>

#include <SwiftShims/HeapObject.h>

extern void swift_retain(struct HeapObject*);
extern void swift_release(struct HeapObject*);
extern struct HeapObject *swift_allocObject(struct HeapMetadata const *metadata,
											size_t requiredSize,
											size_t requiredAlignmentMask);

typedef struct cell_s {
	struct HeapObject ho;
	int data;
	struct cell_s* next;
} cell_s; 
typedef struct cell_s* cell_t;



static void deinitCell(struct HeapObject *_obj) {
	cell_t obj = (cell_t)(_obj);
    printf("native deinitCell called on %p with data %d\n", obj, obj->data);
	swift_release(obj->next);
}

static cell_t allocCell(int x, cell_t n) {
	extern const struct HeapMetadata _TMC12RefCountTest4Cell; // Cell HeapMetadata
	cell_t result = (cell_t)swift_allocObject(&_TMC12RefCountTest4Cell, sizeof(cell_s), 7);
	result->data = x;
	result->next = n;
	return result;
}

cell_t
_swift_make_cell(int x, cell_t next) {
	return allocCell(x, next);
}

void
_swift_dump_list(cell_t head) {
	cell_t orig = head;
	printf("isa is %p\n", head->ho.metadata);
	printf("Start dump\n");
	while (head != NULL) {
		printf("\t%p data=%d, rc=%d\n", head, head->data, head->ho.refCount);
		head = head->next;
	}
	printf("End dump\n");
	swift_release(orig);
}


			
