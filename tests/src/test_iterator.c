#include "tests.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../src/data_structures.h"

void testAllocIterator() {
  SimpleNode node1, node2;
  Iterator* iter;
  TestStruct test1, test2;

  test1.member = 1;
  test2.member = 2;
  node1.head = &test1;
  node1.tail = &node2;
  node2.head = &test2;
  
  iter = allocIterator(&node1, SIMPLE_NODE);

  assert(iterGetNext(iter) == &test1);
  assert(iterGetNext(iter) == &test2);

  printSuccess();
}
