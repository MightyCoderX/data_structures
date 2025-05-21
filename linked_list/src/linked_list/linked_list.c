#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

#define linkedlist_append(LLNodeType, value)                                                       \
    LLNodeType* new = malloc(sizeof(*new));                                                        \
    new->value = value;                                                                            \
    new->next = NULL;                                                                              \
    if(p_linkedlist->tail != NULL) {                                                               \
        ((LLNodeType*)p_linkedlist->tail)->next = new;                                             \
    }                                                                                              \
    if(p_linkedlist->head == NULL) {                                                               \
        p_linkedlist->head = new;                                                                  \
    }                                                                                              \
    p_linkedlist->tail = new;                                                                      \
    p_linkedlist->size += 1;

LinkedList linkedlist_init() {
    LinkedList list = { NULL, NULL, 0 };
    return list;
}

void linkedlist_append_int(LinkedList* p_linkedlist, int value) {
    linkedlist_append(LLNodeInt, value);
}

void linkedlist_append_float(LinkedList* p_linkedlist, float value) {
    linkedlist_append(LLNodeFloat, value);
}
void linkedlist_append_double(LinkedList* p_linkedlist, double value) {
    linkedlist_append(LLNodeDouble, value);
}
void linkedlist_append_generic(LinkedList* p_linkedlist, void* p_data) {
    linkedlist_append(LLNodeGeneric, p_data);
}

void linkedlist_insert_int(LinkedList* p_linkedlist, size_t index, int value) {
    LLNodeInt* new = malloc(sizeof(*new));
    new->value = value;

    LLNodeInt* prev = NULL;
    LLNodeInt* curr = p_linkedlist->head;
    size_t i = 0;
    while(curr != NULL && i < index && i < p_linkedlist->size) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if(prev != NULL) {
        prev->next = new;
    } else {
        p_linkedlist->head = new;
    }

    if(curr == NULL) {
        p_linkedlist->tail = new;
    }

    new->next = curr;
}
void linkedlist_insert_float(LinkedList* p_linkedlist, size_t index, float value);
void linkedlist_insert_double(LinkedList* p_linkedlist, size_t index, double value);
void linkedlist_insert_generic(LinkedList* p_linkedlist, size_t index, void* data);

void linkedlist_remove_int(LinkedList* p_linkedlist, int value);
void linkedlist_remove_float(LinkedList* p_linkedlist, float value);
void linkedlist_remove_double(LinkedList* p_linkedlist, double value);
void linkedlist_remove_generic(LinkedList* p_linkedlist, bool (*matches)(LLNodeGeneric* p_node));

int linkedlist_get_int(LinkedList* p_linkedlist, size_t index);
float linkedlist_get_float(LinkedList* p_linkedlist, size_t index);
double linkedlist_get_double(LinkedList* p_linkedlist, size_t index);
void* linkedlist_get_generic(LinkedList* p_linkedlist, size_t index);
