#include "data_structures.h"
#include <stdlib.h>

LinkedList* allocLinkedList() {
  LinkedList* list = calloc(1, sizeof(LinkedList));

  list->first = list->last = allocSimpleNode();
  list->size = 0;

  return list;
}

void linkedListAppend(LinkedList* list, void* append) {
  list->last->head = append;
  list->last = list->last->tail = allocSimpleNode();
  list->size++;
}

Iterator* linkedListGetIterator(const LinkedList* list) {
  return allocIterator(list->first);
}
