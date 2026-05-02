
/**
 * @file tree.h
 * @brief Binary Search Tree (BST) implementation.
 *
 * This module implements a binary search tree where for each node,
 * all values in the left subtree are less than the node's value,
 * and all values in the right subtree are greater or equal.
 */

/**
 * @struct TreeNode
 * @brief A single node in the binary search tree.
 */
typedef struct TreeNode tree_node_t;

typedef struct TreeNode {
	int value;              /**< Integer value stored in this node */
	tree_node_t* right;     /**< Pointer to the right child (greater values) */
	tree_node_t* left;      /**< Pointer to the left child (lesser values) */
} tree_node_t;

/**
 * @struct Tree
 * @brief Container structure for the binary search tree.
 */
typedef struct Tree {
	tree_node_t* root;  /**< Pointer to the root node of the tree */
	int items;          /**< Total number of nodes in the tree */
} tree_t;

/**
 * @brief Creates a new tree with a root node containing the given value.
 *
 * @param init_value Integer value for the root node.
 * @return Pointer to the newly created tree.
 */
tree_t* tree_new(int init_value);

/**
 * @brief Adds a new node with the given value to the tree.
 *
 * Values less than the current node go to the left subtree,
 * values greater or equal go to the right subtree.
 *
 * @param tree Pointer to the tree structure.
 * @param new_value Integer value to insert.
 */
void tree_add_node(tree_t* tree, int new_value);

/**
 * @brief Traverses and prints the tree in preorder (root, left, right).
 *
 * @param tree Pointer to the tree structure.
 */
void tree_preorder(tree_t* tree);

/**
 * @brief Traverses and prints the tree in inorder (left, root, right).
 *
 * For a BST, this produces values in sorted ascending order.
 *
 * @param tree Pointer to the tree structure.
 */
void tree_inorder(tree_t* tree);

/**
 * @brief Prints a visual tree representation with branch characters.
 *
 * Uses Unicode box-drawing characters (├──, └──, │) to display
 * the tree structure in a readable format.
 *
 * @param tree Pointer to the tree structure.
 */
void tree_print(tree_t* tree);

/**
 * @brief Frees all memory associated with the tree and its nodes.
 *
 * @param tree Pointer to the tree structure to destroy.
 */
void tree_delete(tree_t* tree);
