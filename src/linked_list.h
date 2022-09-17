#ifndef __ELLYZEUL__GENERIC_DATA_STRUCTURES__LINKED_LIST__
#define __ELLYZEUL__GENERIC_DATA_STRUCTURES__LINKED_LIST__

#include "node.h"
#include "iterator.h"

typedef struct {
  SimpleNode* first;
  SimpleNode* last;
  int size;
} LinkedList;

LinkedList* allocLinkedList();
void linkedListAppend(LinkedList* list, void* append);
Iterator* linkedListGetIterator(const LinkedList* list);

#endif//__ELLYZEUL__GENERIC_DATA_STRUCTURES__LINKED_LIST__
