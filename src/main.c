#include "../lib/tree.h"
// #include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	tree_t* t = tree_new(18);

	tree_add_node(t, 9);
	tree_add_node(t, 30);
	tree_add_node(t, 7);
	tree_add_node(t, 40);
	tree_add_node(t, 22);
	tree_add_node(t, 15);

	printf("root value: %d\n", t->root->value);
	tree_preorder(t);
	tree_inorder(t);

	tree_print(t);
	tree_delete(t);


	return 0;
}
