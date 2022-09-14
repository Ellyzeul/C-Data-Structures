# C Data Structures

A collection of some important data structures for C. They are the most generic possible to be used for general purposes.

## Structures

It stores variables of type `void*` so, whenever you are storing or retrieving, the values must be casted.

### SimpleNode

This is a base structure, you probably won't need to touch this, unless you are contributing to the project. 
There are some types of nodes, for the many types of structures. 
`SimpleNode` only stores the value and a reference for the rest of the linked nodes.

```c
// Struct
typedef struct SimpleNode SimpleNode;
struct SimpleNode {
  void* head;
  SimpleNode* tail;
};

// Example
SimpleNode* node = allocSimpleNode();
TestStruct example;
TestStruct *retrieved;

example.member = 19;
node->head = example;

retrieved = (TestStruct*) node->head;

assert(retrieved->member == example.member);
```

### Iterator

Using structures like lists force you to deal with the Nodes to be able to iterate over the data. 
To avoid that, the `Iterator` interface is provided to simplify things.

```c
// Struct
typedef enum {SIMPLE_NODE} NodeType;
typedef struct {
  NodeType type;
  union {
    SimpleNode* simpleCurrent;
  };
} Iterator;

// Example
SimpleNode node1, node2;
Iterator* iter;
TestStruct test1, test2, *retrieved1, *retrieved2;

test1.member = 1;
test2.member = 2;
node1.head = &test1;
node1.tail = &node2;
node2.head = &test2;

iter = allocIterator(&node1, SIMPLE_NODE);
retrieved1 = (TestStruct*) iterGetNext(iter);
retrieved2 = (TestStruct*) iterGetNext(iter);

assert(retrieved1->member == test1.member);
assert(retrieved2->member == test2.member);
```

An important detail: when the `Iterator` reaches the end, will return `NULL` and the memory allocated will be freed, leaving you with just a pointer and a segfault error if try to access the iterator again.

`Iterator` here is defined as a union, which may look like a bit of memory waste on a first glance but, there's a reason. Since there are more than one type of Node and Iterator only stores one reference, the additional memonry needed even if you are using `SimpleNode` is worth for the access transparent interface that is provided.

### Linked lists

A simple linked list, stores just a reference for the begin of the list, for iteration purposes, the end, for insertion purposes and the number of elements for size control.

```c
// Struct
typedef struct {
  SimpleNode* first;
  SimpleNode* last;
  int size;
} LinkedList;

// Example
LinkedList* list = allocLinkedList();
TestStruct example;
TestStruct *retrieved;

example.member = 42;
linkedListAppend(list, &example);

retrieved = list->first->head;

assert(retrieved->member == example.member);
```

### Stack

Stack is your well-known data structure, so I'm not entering in the details.

```c
// Struct
typedef struct {
  SimpleNode* top;
  int size;
} Stack;

// Example
Stack* stack = allocStack();
TestStruct expected1, expected2, *retrieved1, *retrieved2, *retrieved3;

expected1.member = 1;
expected2.member = 2;

stackPush(stack, &expected1);
stackPush(stack, &expected2);

retrieved1 = (TestStruct*) stackPop(stack);
retrieved2 = (TestStruct*) stackPop(stack);
retrieved3 = (TestStruct*) stackPop(stack);

assert(retrieved1->member == expected2.member);
assert(retrieved2->member == expected1.member);
assert(retrieved3 == NULL);
```

### Queue

Queues follow the FIFO principle, where the first to be appended to the queue will be the first to get out. 
The implementation is quite similar to the linked list, with a reference to the first and the last element, with a counting for the size. The only things that changes are the operations.

```c
// Struct
typedef struct {
  SimpleNode* first;
  SimpleNode* last;
  int size;
} Queue;

// Example
Queue* queue = allocQueue();
TestStruct expected1, expected2, expected3, *retrieved1, *retrieved2, *retrieved3;

expected1.member = 2;
expected2.member = 4;
expected3.member = 6;

queueAppend(queue, &expected1);
queueAppend(queue, &expected2);
retrieved1 = (TestStruct*) queueNext(queue);
retrieved2 = (TestStruct*) queueNext(queue);
queueAppend(queue, &expected3);
retrieved3 = (TestStruct*) queueNext(queue);

assert(retrieved1->member == expected1.member);
assert(retrieved2->member == expected2.member);
assert(retrieved3->member == expected3.member);
```
