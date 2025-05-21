#include <stdio.h>

#include "linked_list/linked_list.h"

void print_ll_int(LinkedList* p_list) {
    LLNodeInt* curr = (LLNodeInt*)p_list->head;
    while(curr != NULL) {
        printf("%d->", ((LLNodeInt*)curr)->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main(int argc, char** argv) {
    LinkedList list = linkedlist_init();
    linkedlist_append_int(&list, 1);
    linkedlist_append_int(&list, 3);
    linkedlist_append_int(&list, 4);
    print_ll_int(&list);

    linkedlist_insert_int(&list, 1, 2);
    print_ll_int(&list);

    return 0;
}
