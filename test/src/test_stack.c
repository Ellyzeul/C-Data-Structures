#include "tests.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../src/data_structures.h"

void testAllocStack() {
  Stack* stack = allocStack();

  assert(stack->top == NULL);
  assert(stack->size == 0);

  printSuccess();
}

void testStackPush() {
  Stack* stack = allocStack();
  TestStruct expected1, expected2, *retrieved1, *retrieved2;

  expected1.member = 1;
  expected2.member = 2;

  stackPush(stack, (void*) &expected1);
  stackPush(stack, (void*) &expected2);

  retrieved1 = (TestStruct*) stack->top->head;
  retrieved2 = (TestStruct*) stack->top->tail->head;

  assert(retrieved1->member == expected2.member);
  assert(retrieved2->member == expected1.member);

  printSuccess();
}

void testStackPop() {
  Stack* stack = allocStack();
  TestStruct expected1, expected2, *retrieved1, *retrieved2, *retrieved3;

  expected1.member = 1;
  expected2.member = 2;

  stackPush(stack, (void*) &expected1);
  stackPush(stack, (void*) &expected2);

  retrieved1 = (TestStruct*) stackPop(stack);
  retrieved2 = (TestStruct*) stackPop(stack);
  retrieved3 = (TestStruct*) stackPop(stack);

  assert(retrieved1->member == expected2.member);
  assert(retrieved2->member == expected1.member);
  assert(retrieved3 == NULL);

  printSuccess();
}
