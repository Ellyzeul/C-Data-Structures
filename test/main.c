#include "src/tests.h"
#include <stdio.h>

void printTestHeader(const char* header) {
  printf("\n%s:\t", header);
}

int main(void) {
  printTestHeader("Node");
  testAllocSimpleNode();

  printTestHeader("Linked List");
  testAllocLinkedList();
  testLinkedListAppend();

  printTestHeader("Iterator");
  testAllocIterator();

  printf("\n\n");
}
