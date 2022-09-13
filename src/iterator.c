#include "data_structures.h"
#include <stdlib.h>

Iterator* allocIterator(SimpleNode* first) {
  Iterator* iter = calloc(1, sizeof(Iterator));

  iter->current = first;

  return iter;
}

void* iterGetNext(Iterator* iter) {
  void* toReturn = iter->current->head;

  if(toReturn == NULL) {
    free(iter);
    return toReturn;
  }
  iter->current = iter->current->tail;

  return toReturn;
}
