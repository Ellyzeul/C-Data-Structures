#include "src/tests.h"
#include <stdio.h>

void printTestHeader(const char* header) {
  printf("\n%s:\t", header);
}

int main(void) {
  printTestHeader("Node");
  testAllocSimpleNode();

  printTestHeader("Iterator");
  testAllocIterator();

  printTestHeader("Linked List");
  testAllocLinkedList();
  testLinkedListAppend();

  printTestHeader("Stack");
  testAllocStack();
  testStackPush();
  testStackPop();

  printf("\n\nAll tests cleared.\n\n");
}
