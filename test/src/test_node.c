#include "tests.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../src/data_structures.h"

void testAllocSimpleNode() {
  SimpleNode* node = allocSimpleNode();

  assert(node->head == NULL);
  assert(node->tail == NULL);

  printf(".");
}
