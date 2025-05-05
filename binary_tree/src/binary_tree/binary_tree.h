#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum { LEFT, RIGHT } BTreeSide;

typedef struct BTreeNode {
    int value;
    struct BTreeNode* left;
    struct BTreeNode* right;
} BTreeNode;

typedef struct {
    BTreeNode* root;
} BinaryTree;

BTreeNode* btree_new_node(int value);
bool btree_is_leaf(BTreeNode* p_node);
void btree_pre_order_traversal(BTreeNode* p_node, void (*visit)(BTreeNode* p_node));
void btree_in_order_traversal(BTreeNode* p_node, void (*visit)(BTreeNode* p_node));
void btree_post_order_traversal(BTreeNode* p_node, void (*visit)(BTreeNode* p_node));
void btree_breadth_first_traversal(BTreeNode* p_node, void (*visit)(BTreeNode* p_node));
BTreeNode* btree_find_node(BTreeNode* p_node, int value);

BinaryTree btree_init(int root_value);
bool btree_is_root(BinaryTree* p_tree, BTreeNode* p_node);
BTreeNode* btree_add_child(BinaryTree* p_tree, int parent_data, BTreeSide side, int data);
size_t btree_depth(BinaryTree* p_tree, int value);
size_t btree_height(BinaryTree* p_tree, int value);
void btree_print(BinaryTree* p_tree);

#endif
