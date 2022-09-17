#include "tests.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../src/node.h"

void testAllocSimpleNode() {
  SimpleNode* node = allocSimpleNode();

  assert(node->head == NULL);
  assert(node->tail == NULL);

  printSuccess();
}
