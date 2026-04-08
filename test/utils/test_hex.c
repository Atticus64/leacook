#include <CUnit/CUnit.h>
#include "../../lib/utils/hex.h"
#include "test_hex.h"

void test_val_hxchar(void) {
    CU_ASSERT(val_hxchar('a') == 11);
    CU_ASSERT(val_hxchar('f') == 15);
    CU_ASSERT(val_hxchar('4') == 4);
}

void test_from_hex(void) {
    CU_ASSERT(from_hex("0x40") == 64);
    CU_ASSERT(from_hex("0xa2") == 162);
    CU_ASSERT(from_hex("XYZ") == 0);
}

void test_upper(void) {
    CU_ASSERT(upper('a') == 'A');
    CU_ASSERT(upper('l') == 'L');
    CU_ASSERT(upper('b') == 'B');
}
