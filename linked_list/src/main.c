#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list/linked_list.h"

void print_ll_int(LinkedList* p_list) {
    LLNodeInt* curr = (LLNodeInt*)p_list->head;
    printf("[%lu]: ", p_list->size);
    while(curr != NULL) {
        printf("%d->", ((LLNodeInt*)curr)->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void validate_ll_int(LinkedList* p_list, int expected_head, int expected_tail) {
    int head_val = ((LLNodeInt*)p_list->head)->value;
    int tail_val = ((LLNodeInt*)p_list->tail)->value;
    assert(head_val == expected_head);
    assert(tail_val == expected_tail);

    printf("head: %d, tail: %d\n", head_val, tail_val);
}

#ifdef DEBUG

#endif /* ifdef DEBUG */

typedef struct {
    int x;
    int y;
} Point;

void point_to_string(LLNodeGeneric* p_node, char** serialized) {
    Point* p = p_node->p_data;
    char* format = "(%d,%d)";
    size_t len = snprintf(NULL, 0, format, p->x, p->y);
    *serialized = malloc(len + 1);
    snprintf(*serialized, len + 1, format, p->x, p->y);
}

int main(int argc, char** argv) {
    /* 
     * Init 
     */
    puts("\n/* Init */");
    LinkedList list = linkedlist_init();
    print_ll_int(&list);

    /*
     * Append 
     */
    puts("\n/* Append */");

    linkedlist_append_int(&list, 1);
    print_ll_int(&list);

    linkedlist_append_int(&list, 3);
    print_ll_int(&list);

    linkedlist_append_int(&list, 4);
    print_ll_int(&list);

    /*
     * Insert
     */
    puts("\n/* Insert */");

    linkedlist_insert_int(&list, 1, 2);
    print_ll_int(&list);

    linkedlist_insert_int(&list, 0, 0);
    print_ll_int(&list);

    linkedlist_insert_int(&list, list.size, 5);
    print_ll_int(&list);

    linkedlist_insert_int(&list, list.size + 100, 6);
    print_ll_int(&list);

    /*
     * Get
     */
    puts("\n/* Get */");

    printf("ll[0]: %d\n", linkedlist_get_int(&list, 0));
    printf("ll[3]: %d\n", linkedlist_get_int(&list, 3));
    printf("ll[6]: %d\n", linkedlist_get_int(&list, 6));

    /*
     * Remove
     */
    puts("\n/* Remove */");

    validate_ll_int(&list, 0, 6);
    linkedlist_remove_int(&list, 0);
    validate_ll_int(&list, 1, 6);
    print_ll_int(&list);

    linkedlist_remove_int(&list, 3);
    validate_ll_int(&list, 1, 6);
    print_ll_int(&list);

    linkedlist_remove_int(&list, 6);
    validate_ll_int(&list, 1, 5);
    print_ll_int(&list);

    /*
     * Free
     */
    puts("\n/* Free */");
    linkedlist_free_int(&list);
    print_ll_int(&list);

    /*
     * Generic LinkedList
     */
    puts("\n/*\n * Generic LinkedList\n */");

    list = linkedlist_init();
    linkedlist_append_generic(&list, (void*)&((Point) { 2, -2 }));
    linkedlist_append_generic(&list, (void*)&((Point) { 3, 5 }));

    printf("%lu\n", list.size);
    Point* p = linkedlist_get_generic(&list, 1);
    printf("(%d, %d)\n", p->x, p->y);
    linkedlist_print(&list, &point_to_string);

    return 0;
}
