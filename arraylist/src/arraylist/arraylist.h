#ifndef ARRAYLIST
#define ARRAYLIST

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int* data;
    size_t capacity;
    size_t len;
} ArrayList;

ArrayList arraylist_init();
ArrayList arraylist_from_array(int data[], size_t length);

void arraylist_extend(ArrayList* p_arraylist, size_t new_len, bool should_copy_old);

size_t arraylist_normalize_index(size_t len, long index);

int arraylist_get(const ArrayList* p_arraylist, long index);
void arraylist_set(ArrayList* p_arraylist, long index, int value);

void arraylist_append(ArrayList* p_arraylist, int value);
void arraylist_insert(ArrayList* p_arraylist, long index, int value);
void arraylist_remove(ArrayList* p_arraylist, long index);

long arraylist_indexof(const ArrayList* p_arraylist, int value);

void arraylist_print(const ArrayList* p_arraylist);

void arraylist_free(ArrayList* p_arraylist);
#endif // !ARRAYLIST
