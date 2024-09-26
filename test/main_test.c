#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../lib/hex.h"

void test_val_hxchar(void)
{
	CU_ASSERT(val_hxchar('a') == 10);
	CU_ASSERT(val_hxchar('f') == 15);
	CU_ASSERT(val_hxchar('4') == 4);
}

void test_from_hex(void) {
	CU_ASSERT(from_hex("0x40") == 64);
	CU_ASSERT(from_hex("0xa2") == 162);
}

int init_s() {
	return 0;
}

int clean_s() {
	return 0;
}

int main() {
	CU_pSuite pSuite = NULL;
	
	 /* initialize the CUnit test registry */  
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
	
	pSuite = CU_add_suite("Suite_1", init_s, clean_s);
	CU_add_test(pSuite, "Validation value of char hex", test_val_hxchar);
	CU_add_test(pSuite, "From string hex", test_from_hex);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	CU_basic_run_tests();
	CU_cleanup_registry();
	return 0;
}


