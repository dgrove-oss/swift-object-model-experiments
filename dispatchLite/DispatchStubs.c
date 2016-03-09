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



dispatch_queue_t
dispatch_make_queue(int data1, int data2) {
	extern const struct HeapMetadata _TMC8Dispatch13DispatchQueue; // DispatchQueue HeapMetadata
	dispatch_queue_t result = (dispatch_queue_t)swift_allocObject(&_TMC8Dispatch13DispatchQueue,
																  sizeof(dispatch_queue_s), 7);
	result->queue_data_1 = data1;
	result->queue_data_2 = data2;
	printf("make_queue: refcount on return %d\n",  result->ho.refCount);
	return result;
}

int
dispatch_increase_data(dispatch_queue_t dq, int inc) {
	printf("%p has isa %p and refcount %d\n", dq, dq->ho.metadata, dq->ho.refCount);
	int old = dq->queue_data_2;
	dq->queue_data_2 += inc;
	return old;
}
		
		
dispatch_source_t
dispatch_make_source(int data) {
	extern const struct HeapMetadata _TMC8Dispatch14DispatchSource; // DispatchSource HeapMetadata
	dispatch_source_t result = (dispatch_source_t)swift_allocObject(&_TMC8Dispatch14DispatchSource,
																	sizeof(dispatch_source_s), 7);
	result->source_data_1 = data;
	return result;
}	

void
dispatch_release(dispatch_object_t obj) {
	printf("release: refcount before %d\n",  obj->ho.refCount);
	swift_release((struct HeapObject*)obj);
	printf("release: refcount after %d\n",  obj->ho.refCount);
}

void
dispatch_retain(dispatch_object_t obj) {
	printf("retain: refcount before %d\n",  obj->ho.refCount);
	swift_retain((struct HeapObject*)obj);
	printf("retain: refcount after %d\n",  obj->ho.refCount);
}

void
dispatch_suspend(dispatch_object_t obj) {
	printf("suspend: %p with refcount %d\n", obj, obj->ho.refCount);
}

void
dispatch_suspend_q(dispatch_queue_t obj) {
	printf("suspend_q: %p with refcount %d\n", obj, obj->ho.refCount);
}


#ifdef __BLOCKS__
void
dispatch_async(dispatch_queue_t queue, dispatch_block_t block) {
	printf("Simulating dispatch_async on %p %d %d by evaling block\n",queue,
		   queue->queue_data_1, queue->queue_data_2);
	block();
}
#endif

void
dispatch_async_f(dispatch_queue_t queue, void *context, dispatch_function_t work) {
	printf("Simulating dispatch_async_f on %p %d %d by evaling block\n",queue,
		   queue->queue_data_1, queue->queue_data_2);
	work(context);
}


void * objc_retainAutoreleasedReturnValue(void *obj) {
    if (obj) {
		swift_retain(obj);
        return obj;
    }
    else return NULL;
}
