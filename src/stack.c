#include "data_structures.h"
#include <stdlib.h>
#include <stdio.h>

Stack* allocStack() {
  Stack* stack = calloc(1, sizeof(Stack));

  stack->top = NULL;
  stack->size = 0;

  return stack;
}

void stackPush(Stack* stack, void* push) {
  SimpleNode* node = allocSimpleNode();

  node->head = push;
  node->tail = stack->top;
  stack->top = node;
  stack->size++;
}

void* stackPop(Stack* stack) {
  void* pop = stack->top ? stack->top->head : NULL;
  SimpleNode* toFree = stack->top;

  if(!pop) return pop;

  stack->top = stack->top->tail;
  stack->size--;

  free(toFree);

  return pop;
}

Iterator* stackGetIterator(const Stack* stack) {
  return allocIterator(stack->top, SIMPLE_NODE);
}
