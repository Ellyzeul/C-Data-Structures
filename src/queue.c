#include "data_structures.h"
#include <stdlib.h>

Queue* allocQueue() {
  Queue* queue = calloc(1, sizeof(Queue));

  queue->first = queue->last = NULL;
  queue->size = 0;

  return queue;
}

void emptyQueueAppend(Queue* queue, void* append) {
  queue->first = queue->last = allocSimpleNode();
  queue->first->head = append;
  queue->size++;
}

void queueAppend(Queue* queue, void* append) {
  if(queue->first == NULL) return emptyQueueAppend(queue, append);

  queue->last = queue->last->tail = allocSimpleNode();
  queue->last->head = append;
  queue->size++;
}

void* queueNext(Queue* queue) {
  void* toReturn = queue->first->head;
  SimpleNode* toFree;
  if(!toReturn) return NULL;

  toFree = queue->first;
  queue->first->tail;
  free(toFree);

  return toReturn;
}

Iterator* queueGetIterator(const Queue* queue) {
  return allocIterator(queue->first, SIMPLE_NODE);
}
