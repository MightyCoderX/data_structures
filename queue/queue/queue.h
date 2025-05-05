#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LinkedQueue;

LinkedQueue queue_init();
bool queue_is_empty(LinkedQueue* p_queue);
void queue_enqueue(LinkedQueue* p_queue, int value);
int queue_dequeue(LinkedQueue* p_queue);

void queue_print(LinkedQueue* p_queue);

void queue_free(LinkedQueue* p_queue);

#endif
