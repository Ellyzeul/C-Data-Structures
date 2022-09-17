#ifndef __ELLYZEUL__GENERIC_DATA_STRUCTURES__ITERATOR__
#define __ELLYZEUL__GENERIC_DATA_STRUCTURES__ITERATOR__

#include "node.h"

typedef struct {
  NodeType type;
  union {
    SimpleNode* simpleCurrent;
  };
} Iterator;

Iterator* allocIterator(SimpleNode* first, NodeType type);
void* iterGetNext(Iterator* iter);

#endif//__ELLYZEUL__GENERIC_DATA_STRUCTURES__ITERATOR__
