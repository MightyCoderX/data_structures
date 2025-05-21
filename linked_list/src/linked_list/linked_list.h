#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdbool.h>
#include <stddef.h>

typedef struct LLNodeInt {
    int value;
    struct LLNodeInt* next;
} LLNodeInt;

typedef struct LLNodeFloat {
    float value;
    struct LLNodeFloat* next;
} LLNodeFloat;

typedef struct LLNodeDouble {
    double value;
    struct LLNodeDouble* next;
} LLNodeDouble;

typedef struct LLNodeGeneric {
    void* p_data;
    struct LLNodeGeneric* next;
} LLNodeGeneric;

typedef struct {
    void* head;
    void* tail;
    size_t size;
} LinkedList;

LinkedList linkedlist_init();

void linkedlist_append_int(LinkedList* p_list, int value);
void linkedlist_append_float(LinkedList* p_list, float value);
void linkedlist_append_double(LinkedList* p_list, double value);
void linkedlist_append_generic(LinkedList* p_list, void* data);

void linkedlist_insert_int(LinkedList* p_list, size_t index, int value);
void linkedlist_insert_float(LinkedList* p_list, size_t index, float value);
void linkedlist_insert_double(LinkedList* p_list, size_t index, double value);
void linkedlist_insert_generic(LinkedList* p_list, size_t index, void* data);

void linkedlist_remove_int(LinkedList* p_list, int value);
void linkedlist_remove_float(LinkedList* p_list, float value);
void linkedlist_remove_double(LinkedList* p_list, double value);
void linkedlist_remove_generic(LinkedList* p_list, bool (*matches)(LLNodeGeneric* p_node));

int linkedlist_get_int(LinkedList* p_list, size_t index);
float linkedlist_get_float(LinkedList* p_list, size_t index);
double linkedlist_get_double(LinkedList* p_list, size_t index);
void* linkedlist_get_generic(LinkedList* p_list, size_t index);

void linkedlist_free_int(LinkedList* p_list);

#endif // !LINKED_LIST
