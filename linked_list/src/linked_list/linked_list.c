#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

#define linkedlist_append(LLNodeType, value)                                                       \
    LLNodeType* new = malloc(sizeof(*new));                                                        \
    new->value = value;                                                                            \
    new->next = NULL;                                                                              \
    if(p_list->tail != NULL) {                                                                     \
        ((LLNodeType*)p_list->tail)->next = new;                                                   \
    }                                                                                              \
    if(p_list->head == NULL) {                                                                     \
        p_list->head = new;                                                                        \
    }                                                                                              \
    p_list->tail = new;                                                                            \
    p_list->size++;

#define linkedlist_insert(LLNodeType, index, value)                                                \
    LLNodeType* new = malloc(sizeof(*new));                                                        \
    new->value = value;                                                                            \
    LLNodeType* prev = NULL;                                                                       \
    LLNodeType* curr = p_list->head;                                                               \
    size_t i = 0;                                                                                  \
    while(curr != NULL && i < index && i < p_list->size) {                                         \
        prev = curr;                                                                               \
        curr = curr->next;                                                                         \
        i++;                                                                                       \
    }                                                                                              \
    if(prev != NULL) {                                                                             \
        prev->next = new;                                                                          \
    } else {                                                                                       \
        p_list->head = new;                                                                        \
    }                                                                                              \
    if(curr == NULL) {                                                                             \
        p_list->tail = new;                                                                        \
    }                                                                                              \
    new->next = curr;                                                                              \
    p_list->size++;

#define linkedlist_get(LLNodeType, value)                                                          \
    LLNodeType* curr = p_list->head;                                                               \
    size_t i = 0;                                                                                  \
    while(curr != NULL && i < index) {                                                             \
        curr = curr->next;                                                                         \
        i++;                                                                                       \
    }                                                                                              \
    return curr->value;

LinkedList linkedlist_init() {
    LinkedList list = { NULL, NULL, 0 };
    return list;
}

void linkedlist_append_int(LinkedList* p_list, int value) {
    linkedlist_append(LLNodeInt, value);
}

void linkedlist_append_float(LinkedList* p_list, float value) {
    linkedlist_append(LLNodeFloat, value);
}
void linkedlist_append_double(LinkedList* p_list, double value) {
    linkedlist_append(LLNodeDouble, value);
}
void linkedlist_append_generic(LinkedList* p_list, void* p_data) {
    linkedlist_append(LLNodeGeneric, p_data);
}

void linkedlist_insert_int(LinkedList* p_list, size_t index, int value) {
    linkedlist_insert(LLNodeInt, index, value);
}
void linkedlist_insert_float(LinkedList* p_list, size_t index, float value) {
    linkedlist_insert(LLNodeFloat, index, value);
}
void linkedlist_insert_double(LinkedList* p_list, size_t index, double value) {
    linkedlist_insert(LLNodeDouble, index, value);
}

void linkedlist_insert_generic(LinkedList* p_list, size_t index, void* p_data) {
    linkedlist_insert(LLNodeGeneric, index, p_data);
}

void linkedlist_remove_int(LinkedList* p_list, int value) {
    if(p_list->head == NULL) return;

    LLNodeInt pre_head = { .next = p_list->head };
    LLNodeInt* prev = &pre_head;

    while(prev->next != NULL) {
        if(prev->next->value == value) {
            break;
        }

        prev = prev->next;
    }

    LLNodeInt* target = prev->next;
    if(target == p_list->head) {
        p_list->head = target->next;
    } else {
        if(target == p_list->tail) {
            p_list->tail = prev;
        }
        prev->next = target->next;
    }
    free(target);
    p_list->size--;
}
void linkedlist_remove_float(LinkedList* p_list, float value);
void linkedlist_remove_double(LinkedList* p_list, double value);
void linkedlist_remove_generic(LinkedList* p_list, bool (*matches)(LLNodeGeneric* p_node));

int linkedlist_get_int(LinkedList* p_list, size_t index) {
    linkedlist_get(LLNodeInt, value);
}
float linkedlist_get_float(LinkedList* p_list, size_t index) {
    linkedlist_get(LLNodeFloat, value);
}
double linkedlist_get_double(LinkedList* p_list, size_t index) {
    linkedlist_get(LLNodeDouble, value);
}

void* linkedlist_get_generic(LinkedList* p_list, size_t index) {
    linkedlist_get(LLNodeGeneric, p_data);
}

void linkedlist_free_int(LinkedList* p_list) {
    while(p_list->head != NULL) {
        LLNodeInt* old = p_list->head;
        p_list->head = old->next;
        free(old);
    }
    p_list->tail = NULL;
    p_list->size = 0;
}
