#include "./circular.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

node_t* new_node(int val) {
	node_t* n = malloc(sizeof(node_t));

	n->value = val;
	return n;
}

void add_node(node_t *root, node_t *inserted) {

	if (root->next == NULL) {
		root->next = inserted;
		inserted->next = root;
		return;
	}

	node_t *head = root->next;
	while (true) {
		head = head->next;
		if (head == root->next) {
			break;
		}
	}
	inserted->next = head->next;
	head->next = inserted;
	return;
}

void delete_node(node_t *root, int value) {
	node_t *curr = root->next;
	node_t *prev = root;
	while (true) {
		if (curr->value == value) {
			prev->next = curr->next;
			int val = curr->value;
			printf("del: %d\n", val);
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}

}

void add_end(node_t* init, node_t* new_node) {
	if (init == NULL || new_node == NULL) 
		return;

	if (init->next == NULL) {
		init->next = new_node;
		new_node->next = init;
		return;
	}

	node_t *curr = init;

	// obtener ultimo
	while (true) {
		curr = curr->next;
		if (curr->next == init) 
			break;
	}

	curr->next = new_node;
	new_node->next = init;
	/* printf("last: *(%p) = %d\n", curr, curr->value); */
	/* printf("init: *(%p) = %d\n", init, init->value); */
}

void delete_list(node_t* elem) {

	if (elem->next == NULL) {
		free(elem);
	}

	node_t *head = elem;
	node_t *curr = elem;
	while (true) {
		curr = head;
		head = head->next;
		free(curr);
		if (head == elem)
			break;
	}
}

void print_list(node_t *last) {
	if (last == NULL)
		return;

	node_t *head = last->next;
	while (true) {
		printf("%d ", head->value);
		head = head->next;
		if (head == last->next)
			break;
	}
	printf("\n");
}

void log_node(node_t *node, const char *tag) {
	printf("%s: %d\n", tag, node->value);
	printf("%s addr: %p\n", tag, node->next);
}

list_t* new_list() {
	list_t *list = malloc(sizeof(list_t));
	list->count = 0;
	list->head = NULL;

	return list;
}

void list_insert_node(list_t *list, int value) {

	node_t* node = new_node(value);
	if (list->head == NULL) {
		list->head = node;
		list->count += 1;
		return;
	}

	add_end(list->head, node);
	list->count += 1;
}

void list_delete_node(list_t *list, int value) {
	if (list->head == NULL) 
		return;

	delete_node(list->head, value);
	list->count -= 1;
}

void list_search(list_t *list, int value) {
	node_t *curr = list->head;
	node_t *head = list->head;
	int i = 1;
	while (true) {
		if (curr->value == value) {
			printf("Encontrado en la pos %d\n", i);
			return;
		}
		curr = curr->next;
		if (curr == head)
			break;
		i++;
	}

	printf("No existe el elemento con el valor: %d\n", value);
	
}

void list_log(list_t *list) {
	node_t *curr = list->head;
	node_t *head = list->head;
	printf("-----------------\n");
	while (true) {
		printf("%d ", curr->value);
		curr = curr->next;
		if (curr == head)
			break;
	}

	printf("\nelems: %d\n", list->count);
}

void del_list(list_t *list) {
	delete_list(list->head);

	free(list);
}
