#include "./stack.h"
#include <stdlib.h>
#include <stdio.h>

stack_t* create_st() {
	
	stack_t* new_stack = malloc(sizeof(stack_t));

	new_stack->count = 0;
	new_stack->bottom = malloc(sizeof(elem_t));
	new_stack->bottom->value = 'Z';
	
	return new_stack;
}	

void push(stack_t* stack, char elem) {
	elem_t* new_elem = malloc(sizeof(elem_t));
	new_elem->value = elem;
	stack->count++;

	printf("pushed %c\n", elem);
	elem_t* curr = stack->bottom;

	while(curr != NULL) {
		if (curr->next == NULL) {
			curr->next = new_elem;
			break;
		}

		curr = curr->next;
	}

}

void pop(stack_t* stack, char elem, int position) {

	elem_t* curr = stack->bottom;
	elem_t* prev = NULL;

	while(curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}

	printf("poped %c\n", elem);
	if (curr->value == elem) {
		// printf("prev %p\n", prev);
		// printf("curr %p\n", curr);
		if (prev == NULL)  {
			free(curr);
		} else {
			free(prev->next);
			prev->next = NULL;
		}
	} else {
		printf("[ERROR]: Se esperaba un parentesis en la posicion %d\n", position);
	}

}



