#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

LinkedQueue queue_init() {
    return (LinkedQueue) { NULL, NULL };
}

bool queue_is_empty(LinkedQueue* p_queue) {
    return p_queue->head == NULL;
}

void queue_enqueue(LinkedQueue* p_queue, BTreeNode* p_node) {
    QueueNode* new_elem = malloc(sizeof(*new_elem));

    if(new_elem == NULL) {
        fprintf(stderr, "enqueue: Error while allocating memory\n");
        return;
    }

    new_elem->p_node = p_node;

    if(queue_is_empty(p_queue)) {
        p_queue->head = new_elem;
        p_queue->tail = new_elem;
    } else {
        p_queue->tail->next = new_elem;
        p_queue->tail = new_elem;
        new_elem->next = NULL;
    }
}

BTreeNode* queue_dequeue(LinkedQueue* p_queue) {
    BTreeNode* value = p_queue->head->p_node;
    QueueNode* next = p_queue->head->next;
    free(p_queue->head);
    p_queue->head = next;

    return value;
}

void queue_print(LinkedQueue* p_queue) {
    QueueNode* current = p_queue->head;
    while(current != NULL) {
        printf("'%p'->", current->p_node);
        current = current->next;
    }
    printf("NULL\n");
}

void queue_free(LinkedQueue* p_queue) {
    while(p_queue->head != NULL) {
        QueueNode* old = p_queue->head;
        p_queue->head = p_queue->head->next;
        free(old);
    }
}
