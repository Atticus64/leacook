#include "../lib/circular.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	list_t* cl = new_list();
	list_insert_node(cl, 55);
	list_insert_node(cl, 24);
	list_insert_node(cl, 67);
	list_insert_node(cl, 101);
	list_log(cl); 
	list_delete_node(cl, 67);
	list_log(cl); 
	list_search(cl, 77);
	list_insert_node(cl, 88);
	list_log(cl); 
	list_search(cl, 101);
	int* items = list_get_items(cl);
	for (int i = 0; i < cl->count; i++) {
		printf("%d ", items[i]);
	}
	printf("\n");

	del_list(cl);
	free(items);
	
	return 0;
}
