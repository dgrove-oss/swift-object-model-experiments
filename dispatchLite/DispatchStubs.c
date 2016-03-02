#include <SwiftShims/HeapObject.h>

#include <stdio.h>

extern void swift_retain(struct HeapObject*);
extern void swift_release(struct HeapObject*);
extern struct HeapObject *swift_allocObject(struct HeapMetadata const *metadata,
											size_t requiredSize,
											size_t requiredAlignmentMask);

#include "dispatchAPI.h"

typedef struct dispatch_object_s {
	struct HeapObject ho;
	void *do_ctxt;
	void *do_finalizer;
} dispatch_object_s;

typedef struct dispatch_queue_s {
	struct HeapObject ho;
	void *do_ctxt;
	void *do_finalizer;
	int queue_data_1; // will always be even
	int queue_data_2;
} dispatch_queue_s; 

typedef struct dispatch_source_s {
	struct HeapObject ho;
	void *do_ctxt;
	void *do_finalizer;
	int source_data_1; // will always be odd
} dispatch_source_s; 



dispatch_queue_t dispatch_make_queue(int data1, int data2) {
	extern const struct HeapMetadata _TMC13DispatchTypes13DispatchQueue; // DispatchQueue HeapMetadata
	dispatch_queue_t result = (dispatch_queue_t)swift_allocObject(&_TMC13DispatchTypes13DispatchQueue,
																  sizeof(dispatch_queue_s), 7);
	result->queue_data_1 = data1;
	result->queue_data_2 = data2;
	return result;
}

int dispatch_increase_data(dispatch_queue_t dq, int inc) {
	printf("%p has isa %p\n", dq, dq->ho.metadata);
	int old = dq->queue_data_2;
	dq->queue_data_2 += inc;
	return old;
}
		
		
extern dispatch_source_t dispatch_make_source(int);

extern void dispatch_release(dispatch_object_t);

extern void dispatch_retain(dispatch_object_t);




/*
static void deinitCell(heap_object_t *_obj) {
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
*/
