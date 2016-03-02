
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

/*
 * A sampling of API functions from dispatch to
 * cover some of the interesting cases we have 
 * hit so far in the Swift import of dispatch on Linux
 */

extern dispatch_queue_t dispatch_make_queue(int, int);

extern dispatch_source_t dispatch_make_source(int);

extern void dispatch_release(dispatch_object_t);

extern void dispatch_retain(dispatch_object_t);

extern int dispatch_increase_data(dispatch_queue_t, int);

extern void dispatch_set_finalizer(dispatch_object_t, dispatch_function_t);
