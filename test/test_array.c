#include <CUnit/CUnit.h>
#include "../lib/array.h"
#include "test_array.h"

void test_new_array_valid(void) {
    Nums* list = new_array(5);
    CU_ASSERT_PTR_NOT_NULL(list);
    CU_ASSERT_EQUAL(list->count, 0);
    CU_ASSERT_EQUAL(list->capacity, 5);
    del_array(list);
}

void test_new_array_invalid(void) {
    Nums* list = new_array(3);
    CU_ASSERT_PTR_NULL(list);
}

void test_array_append_single(void) {
    Nums* list = new_array(10);
    array_append(42, list);
    CU_ASSERT_EQUAL(list->count, 1);
    CU_ASSERT_EQUAL(list->items[0], 42);
    del_array(list);
}

void test_array_append_multiple(void) {
    Nums* list = new_array(10);
    array_append(1, list);
    array_append(2, list);
    array_append(3, list);
    CU_ASSERT_EQUAL(list->count, 3);
    CU_ASSERT_EQUAL(list->items[0], 1);
    CU_ASSERT_EQUAL(list->items[1], 2);
    CU_ASSERT_EQUAL(list->items[2], 3);
    del_array(list);
}

void test_array_append_resize(void) {
    Nums* list = new_array(2);
    for (int i = 0; i < 10; i++) {
        array_append(i * 10, list);
    }
    CU_ASSERT_EQUAL(list->count, 10);
    CU_ASSERT(list->capacity >= 10);
    for (int i = 0; i < 10; i++) {
        CU_ASSERT_EQUAL(list->items[i], i * 10);
    }
    del_array(list);
}

void test_array_count_tracking(void) {
    Nums* list = new_array(5);
    CU_ASSERT_EQUAL(list->count, 0);
    array_append(100, list);
    CU_ASSERT_EQUAL(list->count, 1);
    array_append(200, list);
    CU_ASSERT_EQUAL(list->count, 2);
    array_append(300, list);
    CU_ASSERT_EQUAL(list->count, 3);
    del_array(list);
}

void test_array_no_leak(void) {
    Nums* list = new_array(5);
    array_append(1, list);
    array_append(2, list);
    array_append(3, list);
    del_array(list);
}
