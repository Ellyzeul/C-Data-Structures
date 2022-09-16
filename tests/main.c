#include "src/tests.h"
#include <stdio.h>
#include <stdlib.h>

void printTestHeader(const char* header) {
  printf("\n%s:\t", header);
}

void resetColorsOnExit() {
  printf("\e[0m");
}

int main(void) {
  atexit(resetColorsOnExit);

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

  printTestHeader("Queue");
  testAllocQueue();
  testQueueAppend();
  testQueueAppend();
  testQueueGetIterator();

  printf("\n\nAll tests cleared.\n\n");
}
