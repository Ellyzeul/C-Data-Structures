#ifndef __ELLYZEUL__GENERIC_DATA_STRUCTURES__QUEUE__
#define __ELLYZEUL__GENERIC_DATA_STRUCTURES__QUEUE__

#include "node.h"
#include "iterator.h"

typedef struct {
  SimpleNode* first;
  SimpleNode* last;
  int size;
} Queue;

Queue* allocQueue();
void queueAppend(Queue* queue, void* append);
void* queueNext(Queue* queue);
Iterator* queueGetIterator(const Queue* queue);

#endif//__ELLYZEUL__GENERIC_DATA_STRUCTURES__QUEUE__
