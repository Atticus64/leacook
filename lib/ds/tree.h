
typedef struct TreeNode tree_node_t;

typedef struct TreeNode {
	int value;
	tree_node_t* right;
	tree_node_t* left;
} tree_node_t;

typedef struct Tree {
	tree_node_t* root;
	int items;
} tree_t;

/**
 * 
 * Create a new Tree from a init value for the root
 */
tree_t* tree_new(int init_value);

void tree_add_node(tree_t* tree, int new_value);

void tree_preorder(tree_t* tree);

void tree_inorder(tree_t* tree);

void tree_print(tree_t* tree);

void tree_delete(tree_t* tree);

