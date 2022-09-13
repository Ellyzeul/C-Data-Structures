#include "data_structures.h"
#include <stdlib.h>

Iterator* allocIterator(SimpleNode* first, NodeType type) {
  Iterator* iter = calloc(1, sizeof(Iterator));

  iter->type = type;
  iter->simpleCurrent = first;

  return iter;
}

void* iterGetNext(Iterator* iter) {
  void* toReturn;
  switch (iter->type) {
    case SIMPLE_NODE:
      toReturn = iter->simpleCurrent->head;
      if(toReturn != NULL) iter->simpleCurrent = iter->simpleCurrent->tail;
      break;
  }

  if(toReturn == NULL) free(iter);

  return toReturn;
}
