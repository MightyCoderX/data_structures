#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include <stdbool.h>

#include "../binary_tree.h"

typedef struct QueueNode {
    BTreeNode* p_node;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* head;
    QueueNode* tail;
} LinkedQueue;

LinkedQueue queue_init();
bool queue_is_empty(LinkedQueue* p_queue);
void queue_enqueue(LinkedQueue* p_queue, BTreeNode* p_node);
BTreeNode* queue_dequeue(LinkedQueue* p_queue);

void queue_print(LinkedQueue* p_queue);

void queue_free(LinkedQueue* p_queue);

#endif
