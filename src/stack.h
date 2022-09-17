#ifndef __ELLYZEUL__GENERIC_DATA_STRUCTURES__STACK__
#define __ELLYZEUL__GENERIC_DATA_STRUCTURES__STACK__

#include "node.h"
#include "iterator.h"

typedef struct {
  SimpleNode* top;
  int size;
} Stack;

Stack* allocStack();
void stackPush(Stack* stack, void* push);
void* stackPop(Stack* stack);
Iterator* stackGetIterator(const Stack* stack);

#endif//__ELLYZEUL__GENERIC_DATA_STRUCTURES__STACK__
