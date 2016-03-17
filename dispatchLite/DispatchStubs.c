#include <stdio.h>
#include <malloc.h>

#include "dispatchAPI.h"

typedef struct dispatch_object_s {
	void *do_ctxt;
	void *do_finalizer;
} dispatch_object_s;

typedef struct dispatch_queue_s {
	void *do_ctxt;
	void *do_finalizer;
	int queue_data_1; // will always be even
	int queue_data_2;
} dispatch_queue_s; 

typedef struct dispatch_source_s {
	void *do_ctxt;
	void *do_finalizer;
	int source_data_1; // will always be odd
} dispatch_source_s; 

typedef struct dispatch_semaphore_s {
	int x;
} dispatch_semaphore_s; 


dispatch_queue_t
dispatch_queue_create(int data1, int data2) {
	dispatch_queue_t result = (dispatch_queue_t)malloc(sizeof(dispatch_queue_s));
	result->queue_data_1 = data1;
	result->queue_data_2 = data2;
	printf("alloc queue %p\n",result);
	return result;
}

int
dispatch_increase_data(dispatch_queue_t dq, int inc) {
	int old = dq->queue_data_2;
	dq->queue_data_2 += inc;
	return old;
}
		
		
dispatch_semaphore_t
dispatch_semaphore_create() {
	dispatch_semaphore_t result = (dispatch_semaphore_t)malloc(sizeof(dispatch_semaphore_s));
	printf("alloc semaphore %p\n",result);
	return result;
}	

dispatch_source_t
dispatch_source_create(int data) {
	dispatch_source_t result = (dispatch_source_t)malloc(sizeof(dispatch_source_s));
	result->source_data_1 = data;
	printf("alloc source %p\n",result);
	return result;
}	

void
dispatch_release(dispatch_object_t obj) {
	printf("release: %p\n",  obj);
	free(obj);
}

void
dispatch_retain(dispatch_object_t obj) {
	printf("retain: %p\n",  obj);
}



void
dispatch_suspend(dispatch_object_t obj) {
	printf("suspend: %p\n", obj);
}

void
dispatch_suspend_q(dispatch_queue_t obj) {
	printf("suspend_q: %p\n", obj);

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
	printf("Simulating dispatch_async_f on %p %d %d by calling function\n",queue,
		   queue->queue_data_1, queue->queue_data_2);
	work(context);
}

