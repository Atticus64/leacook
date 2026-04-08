#include "./array.h"

Nums* new_array(size_t capacity) {

	Nums* list = malloc(sizeof(Nums));
	if (capacity < 1) {
		printf("Error al crear array con capacidad %zu\n", capacity);
		free(list);
		return NULL;
	}
	list->capacity = capacity;
	list->items = malloc(list->capacity * sizeof(int));
	if (!list->items) {
		free(list);
		printf("Error al hacer el realloc :(\n");
		return NULL;
	}

	list->count = 0;

	return list;
}

void array_append(int num, Nums* list) {

	if (list->count >= list->capacity) {
		size_t new_capacity = (list->capacity == 0) ? 10 : list->capacity * 2;
        void* temp = realloc(list->items, new_capacity * sizeof(int));
        if (!temp) {
            printf("Error al hacer el realloc :(\n");
            return;
        }
        list->items = temp;
        list->capacity = new_capacity;
	}

	list->items[list->count++] = num;
}

void del_array(Nums* list) {

	free(list->items);
	free(list);
}

