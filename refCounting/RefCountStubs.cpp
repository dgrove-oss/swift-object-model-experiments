#include <stdio.h>

#include <swift/Runtime/HeapObject.h>

using namespace swift;

struct Cell : HeapObject {
	int data;
	struct Cell* next;
};

static void deinitCell(HeapObject *_obj) {
	Cell* obj = static_cast<Cell*>(_obj);
    printf("native deinitCell called on %p with data %d\n", obj, obj->data);
	swift_release(obj->next);
}

static Cell* allocCell(int x, Cell* n) {
	extern const HeapMetadata _TMC12RefCountTest4Cell; // Cell HeapMetadata
	auto result = static_cast<Cell*>(swift_allocObject(&_TMC12RefCountTest4Cell, sizeof(Cell), alignof(Cell)-1));
	result->data = x;
	result->next = n;
	return result;
}

extern "C"
Cell*
_swift_make_cell(int x, Cell* next) {
	return allocCell(x, next);
}

extern "C"
void
_swift_dump_list(Cell* head) {
	Cell* orig = head;
	printf("isa is %p\n", head->metadata);
	printf("Start dump\n");
	while (head != NULL) {
		printf("\t%p data=%d, rc=%d\n", head, head->data, head->refCount);
		head = head->next;
	}
	printf("End dump\n");
	swift_release(orig);
}


			
