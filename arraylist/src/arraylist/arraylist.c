#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "arraylist.h"

ArrayList arraylist_init() {
    size_t capacity = 0;
    return (ArrayList) { calloc(capacity, sizeof(int)), capacity, 0 };
}

void arraylist_extend(ArrayList* p_arraylist, size_t new_len, bool should_copy_old) {
    int* old_pointer = p_arraylist->data;
    int* new_pointer;

    if(should_copy_old && p_arraylist->len > 0) {
        new_pointer = realloc(old_pointer, new_len * sizeof(int));
    } else {
        new_pointer = calloc(new_len, sizeof(int));
        free(old_pointer);
    }

    p_arraylist->data = new_pointer;
    p_arraylist->capacity = new_len;
}

ArrayList arraylist_from_array(int data[], size_t length) {
    ArrayList new = arraylist_init();

    arraylist_extend(&new, length, false);

    for(size_t i = 0; i < length; i++) {
        new.data[i] = data[i];
        new.len++;
    }

    return new;
}

size_t arraylist_normalize_index(size_t len, long index) {
    size_t u_index;
    if(index < 0) {
        if(len + index > 0) {
            u_index = len + index;
        } else {
            u_index = 0;
        }
    } else {
        u_index = (size_t)index;
        if(u_index > len) {
            u_index = len - 1;
        }
    }

    return u_index;
}

int arraylist_get(const ArrayList* p_arraylist, long index) {
    size_t u_index = arraylist_normalize_index(p_arraylist->len, index);

    return p_arraylist->data[u_index];
}

void arraylist_set(ArrayList* p_arraylist, long index, int value) {
    size_t u_index = arraylist_normalize_index(p_arraylist->len, index);

    p_arraylist->data[u_index] = value;
}

void arraylist_append(ArrayList* p_arraylist, int value) {
    size_t new_len = p_arraylist->len + 1;

    if(new_len >= p_arraylist->capacity) {
        arraylist_extend(p_arraylist, new_len, true);
    }

    p_arraylist->data[p_arraylist->len] = value;
    p_arraylist->len = new_len;
}

void arraylist_insert(ArrayList* p_arraylist, long index, int value) {
    size_t new_len = p_arraylist->len + 1;

    if(new_len >= p_arraylist->capacity) {
        arraylist_extend(p_arraylist, new_len, true);
    }

    size_t u_index = arraylist_normalize_index(p_arraylist->len, index);

    size_t i;
    for(i = p_arraylist->len; i > u_index; i--) {
        p_arraylist->data[i] = p_arraylist->data[i - 1];
    }

    p_arraylist->data[u_index] = value;
    p_arraylist->len = new_len;
}

void arraylist_remove(ArrayList* p_arraylist, long index) {
    size_t new_len = p_arraylist->len - 1;

    size_t u_index = arraylist_normalize_index(p_arraylist->len, index);

    for(size_t i = u_index; i < p_arraylist->len - 1; i++) {
        p_arraylist->data[i] = p_arraylist->data[i + 1];
    }

    p_arraylist->len = new_len;
}

long arraylist_indexof(const ArrayList* p_arraylist, int value) {
    for(size_t i = 0; i < p_arraylist->len; i++) {
        if(p_arraylist->data[i] == value) {
            return i;
        }
    }

    return -1;
}

void arraylist_print(const ArrayList* p_arraylist) {
    for(size_t i = 0; i < p_arraylist->len; i++) {
        if(i == 0) {
            printf("[");
        }
        printf("%d", arraylist_get(p_arraylist, i));

        if(i == p_arraylist->len - 1) {
            printf("]\n");
        } else {
            printf(", ");
        }
    }
}

void arraylist_free(ArrayList* p_arraylist) {
    free(p_arraylist->data);
    p_arraylist->data = NULL;
    p_arraylist->len = 0;
    p_arraylist->capacity = 0;
}
