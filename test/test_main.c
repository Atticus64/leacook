#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "test_hex.h"
#include "test_array.h"
#include "test_tree.h"

int main(void) {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite core = CU_add_suite("Core Suite", NULL, NULL);
    if (!core) goto cleanup;
    CU_add_test(core, "test_val_hxchar", test_val_hxchar);
    CU_add_test(core, "test_from_hex",   test_from_hex);
    CU_add_test(core, "test_upper",      test_upper);

    CU_pSuite arr = CU_add_suite("Array Suite", NULL, NULL);
    if (!arr) goto cleanup;
    CU_add_test(arr, "test_new_array_valid",       test_new_array_valid);
    CU_add_test(arr, "test_new_array_invalid",     test_new_array_invalid);
    CU_add_test(arr, "test_array_append_single",   test_array_append_single);
    CU_add_test(arr, "test_array_append_multiple", test_array_append_multiple);
    CU_add_test(arr, "test_array_append_resize",   test_array_append_resize);
    CU_add_test(arr, "test_array_count_tracking",  test_array_count_tracking);
    CU_add_test(arr, "test_array_no_leak",         test_array_no_leak);

    CU_pSuite tree = CU_add_suite("Tree Suite", NULL, NULL);
    if (!tree) goto cleanup;
    CU_add_test(tree, "test_tree_new",            test_tree_new);
    CU_add_test(tree, "test_tree_add_single",     test_tree_add_single);
    CU_add_test(tree, "test_tree_add_multiple",   test_tree_add_multiple);
    CU_add_test(tree, "test_tree_add_duplicate",  test_tree_add_duplicate);
    CU_add_test(tree, "test_tree_items_count",    test_tree_items_count);
    CU_add_test(tree, "test_tree_inorder_sorted", test_tree_inorder_sorted);
    CU_add_test(tree, "test_tree_preorder",       test_tree_preorder);
    CU_add_test(tree, "test_tree_delete",         test_tree_delete);
    CU_add_test(tree, "test_tree_no_leak",        test_tree_no_leak);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

cleanup:;
    int failures = CU_get_number_of_failures();
    CU_cleanup_registry();
    return failures;
}

