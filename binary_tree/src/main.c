#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "binary_tree/binary_tree.h"

void print_node(BTreeNode* p_node) {
    printf("%d \n", p_node->value);
}

int main(/*int argc, char** argv*/) {
    BinaryTree tree = btree_init(10);
    btree_add_child(&tree, 10, LEFT, 20);
    btree_add_child(&tree, 20, LEFT, 15);
    btree_add_child(&tree, 20, RIGHT, 21);

    btree_add_child(&tree, 10, RIGHT, 25);
    btree_add_child(&tree, 25, LEFT, 24);
    btree_add_child(&tree, 25, RIGHT, 26);

    printf("depth(10): %lu\n", btree_depth(&tree, 10));
    printf("depth(21): %lu\n", btree_depth(&tree, 21));
    printf("depth(22): %lu\n", btree_depth(&tree, 25));
    printf("height(22): %lu\n", btree_height(&tree, 24));
    printf("height(21): %lu\n", btree_height(&tree, 26));
    printf("height(20): %lu\n", btree_height(&tree, 20));
    printf("height(10): %lu\n", btree_height(&tree, 10));

    btree_pre_order_traversal(tree.root, print_node);

    puts("");
    btree_in_order_traversal(tree.root, print_node);

    puts("");
    btree_post_order_traversal(tree.root, print_node);

    puts("");
    btree_breadth_first_traversal(tree.root, print_node);
    return 0;
}
