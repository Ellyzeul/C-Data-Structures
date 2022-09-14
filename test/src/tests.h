#ifndef __ELLYZEUL__TEST__GENERIC_DATA_STRUCTURES__
#define __ELLYZEUL__TEST__GENERIC_DATA_STRUCTURES__

#include <stdio.h>

typedef struct {
  int member;
} TestStruct;

void printSuccess();

void testAllocSimpleNode();

void testAllocLinkedList();
void testLinkedListAppend();

void testAllocIterator();

void testAllocStack();
void testStackPush();
void testStackPop();

void testAllocQueue();
void testQueueAppend();
void testQueueNext();
void testQueueGetIterator();

#endif//__ELLYZEUL__TEST__GENERIC_DATA_STRUCTURES__
