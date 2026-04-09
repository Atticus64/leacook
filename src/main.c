#include <stdio.h>
#include "../lib/ds/array.h" 
#include "../lib/ds/stack.h" 

int main() {
	Nums* list = new_array(10);
	stack_t* st = create_stack();

	for (int i = 38; i <= 43; ++i) {
		array_append(i, list);
		// pushing ascii chars of int value i 
		push(st, i);
	}

	show_stack(st);
	char top = peek(st);
	printf("peeked %c\n", top);
	for (int x = 0; x < 3; ++x) pop(st);
	show_stack(st);
	printf("empty? %s\n", empty_stack(st) ? "true" : "false");

	printf("list -> ");
	show_array(list);
	printf("Pointer -> %p\n", list->items);
	printf("value -> %d\n", list->items[30]);
	printf("Count -> %zu\n", list->count);
	printf("Capacity -> %zu\n", list->capacity);
	del_array(list);
	del_stack(st);
	return 0;
}
