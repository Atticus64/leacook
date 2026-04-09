#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int *items;
	size_t count;
	size_t capacity;
} Nums;


Nums* new_array(size_t capacity);

void show_array(Nums* list);

void array_append(int num, Nums* list);

void del_array(Nums* list);
