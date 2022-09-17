#ifndef __ELLYZEUL__GENERIC_DATA_STRUCTURES__NODE__
#define __ELLYZEUL__GENERIC_DATA_STRUCTURES__NODE__

typedef enum {SIMPLE_NODE} NodeType;

typedef struct SimpleNode SimpleNode;
struct SimpleNode {
  void* head;
  SimpleNode* tail;
};

SimpleNode* allocSimpleNode();

#endif//__ELLYZEUL__GENERIC_DATA_STRUCTURES__NODE__
