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

////////// Stack ////////////////////////////

typedef struct {
  SimpleNode* top;
  int size;
} Stack;

Stack* allocStack();
void stackPush(Stack* stack, void* push);
void* stackPop(Stack* stack);
Iterator* stackGetIterator(const Stack* stack);

#endif//__ELLYZEUL__GENERIC_DATA_STRUCTURES__
