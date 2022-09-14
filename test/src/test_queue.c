#include "tests.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../src/data_structures.h"

void testAllocQueue() {
  Queue* queue = allocQueue();

  assert(queue->first == NULL);
  assert(queue->first == queue->last);
  assert(queue->size == 0);

  printSuccess();
}

void testQueueAppend() {
  Queue* queue = allocQueue();
  TestStruct expected1, *retrievedFront, *retrievedBack;

  expected1.member = 43;

  queueAppend(queue, (void*) &expected1);
  retrievedFront = (TestStruct*) queue->first->head;
  retrievedBack = (TestStruct*) queue->last->head;

  assert(retrievedFront->member == expected1.member);
  assert(retrievedBack->member == expected1.member);

  printSuccess();
}

void testQueueNext() {
  Queue* queue = allocQueue();
  TestStruct expected1, expected2, expected3, *retrieved1, *retrieved2, *retrieved3;

  expected1.member = 2;
  expected2.member = 4;
  expected3.member = 6;

  queueAppend(queue, (void*) &expected1);
  queueAppend(queue, (void*) &expected2);
  retrieved1 = (TestStruct*) queueNext(queue);
  retrieved2 = (TestStruct*) queueNext(queue);
  queueAppend(queue, (void*) &expected3);
  retrieved3 = (TestStruct*) queueNext(queue);

  assert(retrieved1->member == expected1.member);
  assert(retrieved2->member == expected2.member);
  assert(retrieved3->member == expected3.member);

  printSuccess();
}

void testQueueGetIterator() {

}
