A set of simple test cases for experimenting with the Swift object
model on Linux.

1. refCounting creates a linked list in C and C++ and shows that the
   Swift deinit function will be called when the list is reclaimed by
   refcounting

2. dispatchLite is a simulation of a very stripped down libdispatch
   API to explore options for implementing the Dispatch overlay where
   libdispatch implements the Swift object model.

