#include "linked_list.h"
#include <stdlib.h>
#include "node.h"
#include "iterator.h"

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
  return allocIterator(list->first, SIMPLE_NODE);
}
