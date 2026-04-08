#include <stdio.h>
#include "../lib/array.h" 

int main() {

	Nums* list = new_array(10);

	for (int i = 10; i <= 20; ++i) {
		array_append(i, list);
	}


	printf("[ ");
	for (size_t x = 0; x < list->count; ++x) {
		if (x == list->count - 1) {
			printf("%d ]\n", list->items[x]);
		} else {
			printf("%d, ", list->items[x]);
		}
	}

	printf("Pointer -> %p\n", list->items);
	printf("value -> %d\n", list->items[30]);
	printf("Count -> %zu\n", list->count);
	printf("Capacity -> %zu\n", list->capacity);

	del_array(list);
	return 0;
}
