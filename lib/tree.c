#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tree_t* tree_new(int init_value) {
	tree_t* new_tree = malloc(sizeof(tree_t));

	new_tree->root = malloc(sizeof(tree_node_t));

	new_tree->root->value = init_value;

	return new_tree;
}

void tree_add_node(tree_t *tree, int new_value) {

	tree_node_t* root = tree->root;
	tree_node_t* new_node = malloc(sizeof(tree_node_t));
	new_node->value = new_value;
	tree->items += 1;

	while (root != NULL) {
		if (new_value < root->value) {
			if (root->left == NULL) {
				root->left = new_node;
				break;
			}

			root = root->left;
		} else {
			if (root->right == NULL) {
				root->right = new_node;
				break;
			}

			root = root->right;;
		}
	}

}

void tree_node_inorder(tree_node_t* node) {
	if (node == NULL) return;

	tree_node_inorder(node->left);
	printf("%d ", node->value);
	tree_node_inorder(node->right);
}

void tree_node_preorder(tree_node_t* node) {
	if (node == NULL) return;

	printf("%d ", node->value);
	tree_node_inorder(node->left);
	tree_node_inorder(node->right);
}

void tree_node_print(char* prefix, tree_node_t* node, int isLeft) {
	if (node != NULL) {
		char pretxt[100];
		printf("%s", prefix);
		strcpy(pretxt, prefix); 
		if (isLeft) {
			printf("├──");
			strcat(pretxt, "│   ");
		} else {
			printf("└──"); 
			// pretxt[] = strcat(prefix, "    ");
			strcat(pretxt, "    ");
		}

		// std::cout << (isLeft ? "├──" : "└──" );
		// print the value of the node
		// std::cout << node->letra << "\n"; 
		printf("%d\n", node->value);

		tree_node_print(pretxt, node->right, 1);
		tree_node_print(pretxt, node->left, 0);
	}
}

void tree_preorder(tree_t* tree) {
	tree_node_t* root = tree->root;
	tree_node_preorder(root);
	printf("\n");
}

void tree_inorder(tree_t* tree) {
	tree_node_t* root = tree->root;
	tree_node_inorder(root);
	printf("\n");
}

void tree_print(tree_t* tree) {
	tree_node_t* root = tree->root;
	tree_node_print("", root, 0); 
}

void tree_delete_nodes(tree_node_t* node) {
	if (node == NULL) return;

	tree_delete_nodes(node->left);
	tree_delete_nodes(node->right);
	free(node);
}

void tree_delete(tree_t* tree) {

	tree_delete_nodes(tree->root);
	free(tree);
}


