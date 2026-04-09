#include "./stack.h"
#include <stdlib.h>
#include <stdio.h>

stack_t* create_stack() {
	stack_t* new_stack = malloc(sizeof(stack_t));

	new_stack->count = 0;
	new_stack->top = malloc(sizeof(elem_t));
	new_stack->top->value = 'Z';
	
	return new_stack;
}	

void push(stack_t* stack, char elem) {
	elem_t* new_elem = malloc(sizeof(elem_t));
	new_elem->value = elem;
	stack->count++;

	elem_t* curr = stack->top;

	new_elem->next = curr;
	stack->top = new_elem;
	printf("pushed %c\n", elem);
}

char pop(stack_t* stack) {
	elem_t* curr = stack->top;
	elem_t* new_top = curr->next;

	stack->top = new_top;
	char value = curr->value;
	printf("poped %c\n", value);
	free(curr);
	return value;
}


char peek(stack_t* stack) {
	elem_t* curr = stack->top;
	return curr->value;
}


void show_stack(stack_t* stack) {

	elem_t* curr = stack->top;

	printf("{ ");
	while(curr->next != NULL) {
		if (curr->next->next == NULL) {
			printf("%c ", curr->value);
		} else {
			printf("%c, ", curr->value);
		}

		curr = curr->next;
	}

	printf("}\n");
}

void del_stack(stack_t* stack) {
	if (stack != NULL) {

		elem_t* curr = stack->top->next;

		while (curr != NULL) {
			elem_t* next = curr->next;
			free(curr);
			curr = next;
		}


		if (stack->top != NULL) {
			free(stack->top);
		}
		free(stack);
	}
}
