#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"
#include "queue/queue.h"

BTreeNode* btree_new_node(int value) {
    BTreeNode* new = malloc(sizeof(BTreeNode));
    new->value = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}

BinaryTree btree_init(int root_value) {
    BTreeNode* root = malloc(sizeof(BTreeNode));
    root->value = root_value;
    root->left = NULL;
    root->right = NULL;

    BinaryTree btree = { root };

    return btree;
}

bool btree_is_root(BinaryTree* p_tree, BTreeNode* p_node) {
    return p_tree->root == p_node;
}

bool btree_is_leaf(BTreeNode* p_node) {
    return p_node->left == NULL && p_node->right == NULL;
}

BTreeNode* btree_find_node(BTreeNode* p_node, int value) {
    if(p_node->value == value) {
        return p_node;
    } else if(btree_is_leaf(p_node)) {
        return NULL;
    }

    BTreeNode* left = NULL;
    if(p_node->left != NULL) {
        left = btree_find_node(p_node->left, value);
    }

    BTreeNode* right = NULL;
    if(p_node->right != NULL) {
        right = btree_find_node(p_node->right, value);
    }

    return left == NULL ? right : left;
}

void btree_pre_order_traversal(BTreeNode* p_node, void (*visit)(BTreeNode* p_node)) {
    if(p_node == NULL) {
        return;
    }

    visit(p_node);
    btree_pre_order_traversal(p_node->left, visit);
    btree_pre_order_traversal(p_node->right, visit);
}

void btree_in_order_traversal(BTreeNode* p_node, void (*visit)(BTreeNode* p_node)) {
    if(p_node == NULL) {
        return;
    }

    btree_in_order_traversal(p_node->left, visit);
    visit(p_node);
    btree_in_order_traversal(p_node->right, visit);
}

void btree_post_order_traversal(BTreeNode* p_node, void (*visit)(BTreeNode* p_node)) {
    if(p_node == NULL) {
        return;
    }

    btree_post_order_traversal(p_node->left, visit);
    btree_post_order_traversal(p_node->right, visit);
    visit(p_node);
}

void btree_breadth_first_traversal_internal(
    BTreeNode* p_node, LinkedQueue* p_queue, void (*visit)(BTreeNode*)) {
    if(p_node == NULL) {
        return;
    }

    if(p_node->left != NULL) {
        queue_enqueue(p_queue, p_node->left);
    }
    if(p_node->right != NULL) {
        queue_enqueue(p_queue, p_node->right);
    }

    if(p_node->left != NULL) {
        btree_breadth_first_traversal_internal(p_node->left, p_queue, visit);
    }

    if(p_node->right != NULL) {
        btree_breadth_first_traversal_internal(p_node->right, p_queue, visit);
    }

    while(!queue_is_empty(p_queue)) {
        visit(queue_dequeue(p_queue));
    }
}

void btree_breadth_first_traversal(BTreeNode* p_node, void (*visit)(BTreeNode*)) {
    if(p_node == NULL) {
        return;
    }

    LinkedQueue queue = queue_init();
    queue_enqueue(&queue, p_node);

    btree_breadth_first_traversal_internal(p_node, &queue, visit);
}

size_t btree_depth_internal(BTreeNode* p_current, BTreeNode* p_target, size_t depth) {
    if(p_current == p_target) {
        return depth;
    }

    size_t left = 0;
    if(p_current->left != NULL) {
        left = btree_depth_internal(p_current->left, p_target, depth + 1);
    }
    size_t right = 0;
    if(p_current->right != NULL) {
        right = btree_depth_internal(p_current->right, p_target, depth + 1);
    }

    return left > right ? left : right;
}

size_t btree_height_internal(BTreeNode* p_current, size_t height) {
    if(btree_is_leaf(p_current)) {
        return height;
    }

    size_t left = 0;
    if(p_current->left != NULL) {
        left = btree_height_internal(p_current->left, height + 1);
    }
    size_t right = 0;
    if(p_current->right != NULL) {
        right = btree_height_internal(p_current->right, height + 1);
    }

    return left > right ? left : right;
}

size_t btree_height(BinaryTree* p_tree, int value) {
    BTreeNode* p_target = btree_find_node(p_tree->root, value);
    return btree_height_internal(p_target, 0);
}

size_t btree_depth(BinaryTree* p_tree, int value) {
    BTreeNode* p_target = btree_find_node(p_tree->root, value);
    return btree_depth_internal(p_tree->root, p_target, 0);
}

BTreeNode* btree_add_child(BinaryTree* p_tree, int parent_value, BTreeSide side, int value) {
    BTreeNode* node = btree_new_node(value);

    BTreeNode* p_parent = btree_find_node(p_tree->root, parent_value);

    if(p_parent == NULL) {
        return NULL;
    }

    switch(side) {
    case LEFT:
        p_parent->left = node;
        break;
    case RIGHT:
        p_parent->right = node;
        break;
    }

    return node;
}

void btree_print(BinaryTree* p_tree) {
    ;
}
