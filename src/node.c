#include "node.h"
#include <stdlib.h>

SimpleNode* allocSimpleNode() {
  SimpleNode* node = calloc(1, sizeof(SimpleNode));

  node->head = node->tail = NULL;

  return node;
}
