#include <stdio.h>
#include "../lib/array.h" 

int main() {

	Nums* list = new_array(10);

	for (int i = 10; i < 50; ++i) {
		array_append(i, list);
	}

	for (size_t x = 0; x < list->count; ++x) {
		printf("%d\n", list->items[x]);
	}

	printf("Pointer -> %p\n", list->items);
	printf("value -> %d\n", list->items[0]);

	del_array(list);


	return 0;
}
