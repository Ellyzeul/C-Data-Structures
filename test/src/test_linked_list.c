#include "tests.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../src/data_structures.h"

void testAllocLinkedList() {
  LinkedList* list = allocLinkedList();

  assert(list->first->head == NULL);
  assert(list->first->tail == NULL);
  assert(list->first == list->last);
  assert(list->size == 0);

  printf(".");
}

void testLinkedListAppend() {
  LinkedList* list = allocLinkedList();
  TestStruct expected1, expected2;
  expected1.member = 1;
  expected2.member = 2;
  linkedListAppend(list, (void*) &expected1);
  linkedListAppend(list, (void*) &expected2);

  assert(((TestStruct*) list->first->head)->member == expected1.member);
  assert(((TestStruct*) list->first->tail->head)->member == expected2.member);
  assert(list->first->head == &expected1);
  assert(list->first->tail->head == &expected2);

  printf(".");
}
