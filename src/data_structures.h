#ifndef __ELLYZEUL__GENERIC_DATA_STRUCTURES__
#define __ELLYZEUL__GENERIC_DATA_STRUCTURES__

typedef struct SimpleNode SimpleNode;
struct SimpleNode {
  void* head;
  SimpleNode* tail;
};

SimpleNode* allocSimpleNode();

////////// Iterator /////////////////////////

typedef enum {SIMPLE_NODE} NodeType;
typedef struct {
  NodeType type;
  union {
    SimpleNode* simpleCurrent;
  };
} Iterator;

Iterator* allocIterator(SimpleNode* first, NodeType type);
void* iterGetNext(Iterator* iter);

////////// Linked List //////////////////////

typedef struct {
  SimpleNode* first;
  SimpleNode* last;
  int size;
} LinkedList;

LinkedList* allocLinkedList();
void linkedListAppend(LinkedList* list, void* append);
Iterator* linkedListGetIterator(const LinkedList* list);

#endif//__ELLYZEUL__GENERIC_DATA_STRUCTURES__
