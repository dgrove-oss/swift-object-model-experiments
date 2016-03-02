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
	extern const struct HeapMetadata _TMC12DispatchLite13DispatchQueue; // DispatchQueue HeapMetadata
	dispatch_queue_t result = (dispatch_queue_t)swift_allocObject(&_TMC12DispatchLite13DispatchQueue,
																  sizeof(dispatch_queue_s), 7);
	result->queue_data_1 = data1;
	result->queue_data_2 = data2;
	return result;
}

int dispatch_increase_data(dispatch_queue_t dq, int inc) {
	printf("%p has isa %p and refcount %d\n", dq, dq->ho.metadata, dq->ho.refCount);
	int old = dq->queue_data_2;
	dq->queue_data_2 += inc;
	swift_release(dq); /// TODO: This is not what we want.  Caller needs to not retain dq!
	return old;
}
		
		
dispatch_source_t dispatch_make_source(int data) {
	extern const struct HeapMetadata _TMC12DispatchLite14DispatchSource; // DispatchSource HeapMetadata
	dispatch_source_t result = (dispatch_source_t)swift_allocObject(&_TMC12DispatchLite14DispatchSource,
																	sizeof(dispatch_source_s), 7);
	result->source_data_1 = data;
	return result;
}	

extern void dispatch_release(dispatch_object_t obj) {
	swift_release((struct HeapObject*)obj);
}

extern void dispatch_retain(dispatch_object_t obj) {
	swift_retain((struct HeapObject*)obj);
}




