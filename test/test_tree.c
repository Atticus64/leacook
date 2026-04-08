#include <CUnit/CUnit.h>
#include "../lib/tree.h"
#include "test_tree.h"

void test_tree_new(void) {
    tree_t* tree = tree_new(50);
    CU_ASSERT_PTR_NOT_NULL(tree);
    CU_ASSERT_PTR_NOT_NULL(tree->root);
    CU_ASSERT_EQUAL(tree->root->value, 50);
    CU_ASSERT_EQUAL(tree->items, 1);
    CU_ASSERT_PTR_NULL(tree->root->left);
    CU_ASSERT_PTR_NULL(tree->root->right);
    tree_delete(tree);
}

void test_tree_add_single(void) {
    tree_t* tree = tree_new(10);
    tree_add_node(tree, 5);
    CU_ASSERT_EQUAL(tree->items, 2);
    CU_ASSERT_EQUAL(tree->root->left->value, 5);
    tree_delete(tree);
}

void test_tree_add_multiple(void) {
    tree_t* tree = tree_new(50);
    tree_add_node(tree, 30);
    CU_ASSERT_EQUAL(tree->items, 2);
    tree_add_node(tree, 70);
    CU_ASSERT_EQUAL(tree->items, 3);
    tree_add_node(tree, 20);
    CU_ASSERT_EQUAL(tree->items, 4);
    tree_add_node(tree, 40);
    CU_ASSERT_EQUAL(tree->items, 5);
    tree_add_node(tree, 60);
    CU_ASSERT_EQUAL(tree->items, 6);
    tree_add_node(tree, 80);
    CU_ASSERT_EQUAL(tree->items, 7);

    CU_ASSERT_EQUAL(tree->root->value, 50);
    CU_ASSERT_EQUAL(tree->root->left->value, 30);
    CU_ASSERT_EQUAL(tree->root->right->value, 70);
    CU_ASSERT_EQUAL(tree->root->left->left->value, 20);
    CU_ASSERT_EQUAL(tree->root->left->right->value, 40);
    CU_ASSERT_EQUAL(tree->root->right->left->value, 60);
    CU_ASSERT_EQUAL(tree->root->right->right->value, 80);

    tree_delete(tree);
}

void test_tree_add_duplicate(void) {
    tree_t* tree = tree_new(50);
    tree_add_node(tree, 50);
    CU_ASSERT_EQUAL(tree->items, 2);
    CU_ASSERT_EQUAL(tree->root->right->value, 50);
    tree_delete(tree);
}

void test_tree_items_count(void) {
    tree_t* tree = tree_new(100);
    CU_ASSERT_EQUAL(tree->items, 1);
    tree_add_node(tree, 50);
    CU_ASSERT_EQUAL(tree->items, 2);
    tree_add_node(tree, 150);
    CU_ASSERT_EQUAL(tree->items, 3);
    tree_add_node(tree, 25);
    CU_ASSERT_EQUAL(tree->items, 4);
    tree_add_node(tree, 75);
    CU_ASSERT_EQUAL(tree->items, 5);
    tree_delete(tree);
}

void test_tree_inorder_sorted(void) {
    tree_t* tree = tree_new(50);
    tree_add_node(tree, 30);
    tree_add_node(tree, 70);
    tree_add_node(tree, 20);
    tree_add_node(tree, 40);
    tree_add_node(tree, 60);
    tree_add_node(tree, 80);

    CU_ASSERT_EQUAL(tree->root->left->left->value, 20);
    CU_ASSERT_EQUAL(tree->root->left->right->value, 40);
    CU_ASSERT_EQUAL(tree->root->right->left->value, 60);
    CU_ASSERT_EQUAL(tree->root->right->right->value, 80);

    tree_delete(tree);
}

void test_tree_preorder(void) {
    tree_t* tree = tree_new(50);
    tree_add_node(tree, 30);
    tree_add_node(tree, 70);

    CU_ASSERT_EQUAL(tree->root->value, 50);
    CU_ASSERT_EQUAL(tree->root->left->value, 30);
    CU_ASSERT_EQUAL(tree->root->right->value, 70);

    tree_delete(tree);
}

void test_tree_delete(void) {
    tree_t* tree = tree_new(50);
    tree_add_node(tree, 30);
    tree_add_node(tree, 70);
    tree_add_node(tree, 20);
    tree_add_node(tree, 40);
    tree_add_node(tree, 60);
    tree_add_node(tree, 80);
    tree_delete(tree);
}

void test_tree_no_leak(void) {
    tree_t* tree = tree_new(50);
    tree_add_node(tree, 30);
    tree_add_node(tree, 70);
    tree_add_node(tree, 20);
    tree_add_node(tree, 40);
    tree_add_node(tree, 60);
    tree_add_node(tree, 80);
    tree_delete(tree);
}
