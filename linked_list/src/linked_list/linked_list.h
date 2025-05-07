#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int value;
    void* next;
} LLNodeInt;

typedef struct {
    float value;
    void* next;
} LLNodeFloat;

typedef struct {
    double value;
    void* next;
} LLNodeDouble;

typedef struct {
    void* p_data;
    void* next;
} LLNodeGeneric;

typedef struct {
    void* head;
    size_t size;
} LinkedList;

LinkedList linkedlist_init();

void linkedlist_append_int(LinkedList* p_linkedlist, int value);
void linkedlist_append_float(LinkedList* p_linkedlist, float value);
void linkedlist_append_double(LinkedList* p_linkedlist, double value);
void linkedlist_append_data(LinkedList* p_linkedlist, void* value);

void linkedlist_insert_int(LinkedList* p_linkedlist, int value);
void linkedlist_insert_float(LinkedList* p_linkedlist, float value);
void linkedlist_insert_double(LinkedList* p_linkedlist, double value);
void linkedlist_insert_data(LinkedList* p_linkedlist, void* data);

void linkedlist_remove_int(LinkedList* p_linkedlist, int value);
void linkedlist_remove_float(LinkedList* p_linkedlist, float value);
void linkedlist_remove_double(LinkedList* p_linkedlist, double value);
void linkedlist_remove_data(LinkedList* p_linkedlist, bool (*matches)(LLNodeGeneric* p_node));

#endif // !LINKED_LIST
