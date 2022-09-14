#ifndef __ELLYZEUL__TEST__GENERIC_DATA_STRUCTURES__
#define __ELLYZEUL__TEST__GENERIC_DATA_STRUCTURES__

typedef struct {
  int member;
} TestStruct;

void testAllocSimpleNode();

void testAllocLinkedList();
void testLinkedListAppend();

void testAllocIterator();

void testAllocStack();
void testStackPush();
void testStackPop();

#endif//__ELLYZEUL__TEST__GENERIC_DATA_STRUCTURES__
