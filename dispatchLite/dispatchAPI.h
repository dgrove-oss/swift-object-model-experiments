
/*
 * Enough types to be interesting.
 * Logically dispatch_object_s is the superclass of
 * dispatch_queue_s and dispatch_source_s
 */
struct dispatch_object_s;
struct dispatch_queue_s;
struct dispatch_source_s;

typedef struct dispatch_object_s* dispatch_object_t;
typedef struct dispatch_queue_s* dispatch_queue_t;
typedef struct dispatch_source_s* dispatch_source_t;

typedef void (*dispatch_function_t)(void *);

#ifdef __BLOCKS__
typedef void (^dispatch_block_t)(void);
#endif

/*
 * A sampling of API functions from dispatch to
 * cover some of the interesting cases we have 
 * hit so far in the Swift import of dispatch on Linux
 */

dispatch_queue_t dispatch_make_queue(int, int);

dispatch_source_t dispatch_make_source(int);

void dispatch_release(dispatch_object_t);

void dispatch_retain(dispatch_object_t);

int dispatch_increase_data(dispatch_queue_t, int);

void dispatch_set_finalizer(dispatch_object_t, dispatch_function_t);

#ifdef __BLOCKS__
void dispatch_async(dispatch_queue_t queue, dispatch_block_t block);
#endif

void
dispatch_async_f(dispatch_queue_t queue, void *context, dispatch_function_t work);

