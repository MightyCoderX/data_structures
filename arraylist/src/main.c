#include <stdio.h>

#include "arraylist/arraylist.h"

int main(int argc, char** argv) {
    ArrayList arraylist = arraylist_init();
    arraylist_append(&arraylist, 10);
    arraylist_append(&arraylist, 5);
    arraylist_append(&arraylist, 6);
    arraylist_append(&arraylist, 7);
    arraylist_append(&arraylist, 8);

    printf("%d\n", arraylist_get(&arraylist, 0));
    printf("%d\n", arraylist_get(&arraylist, -1));

    arraylist_print(&arraylist);

    arraylist_set(&arraylist, 0, 1);

    arraylist_print(&arraylist);

    arraylist_insert(&arraylist, 3, 17);
    arraylist_insert(&arraylist, 0, 11);
    arraylist_insert(&arraylist, -1, 13); //TODO: fix: Doesn't append at the end!

    arraylist_print(&arraylist);

    arraylist_remove(&arraylist, 0);
    arraylist_remove(&arraylist, 1);
    arraylist_remove(&arraylist, -1);

    arraylist_print(&arraylist);
    arraylist_free(&arraylist);

    return 0;
}
