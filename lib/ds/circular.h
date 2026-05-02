
/**
 * @file circular.h
 * @brief Circular linked list implementation.
 *
 * This module implements a singly-linked circular list where the last node
 * points back to the first node, forming a cycle.
 */

/**
 * @struct Node
 * @brief A single node in the circular linked list.
 */
typedef struct Node node_t;

typedef struct Node {
  int value;      /**< Integer value stored in this node */
  node_t *next;   /**< Pointer to the next node in the list */
} node_t;

/**
 * @struct List
 * @brief Container structure for the circular linked list.
 */
typedef struct List list_t;

typedef struct List {
	int count;    /**< Number of nodes in the list */
	node_t *head; /**< Pointer to the first node (head) of the list */
} list_t;

/**
 * @brief Creates a new node with the given value.
 *
 * @param val Integer value to store in the node.
 * @return Pointer to the newly created node.
 */
node_t* new_node(int val);

/**
 * @brief Creates a new empty circular list.
 *
 * @return Pointer to the newly created list structure.
 */
list_t* new_list(void);

/**
 * @brief Inserts a new node with the given value into the circular list.
 *
 * @param list Pointer to the list structure.
 * @param value Integer value to insert.
 */
void list_insert_node(list_t* list, int value);

/**
 * @brief Deletes the first node found with the given value.
 *
 * @param list Pointer to the list structure.
 * @param value Integer value to search for and delete.
 */
void list_delete_node(list_t* list, int value);

/**
 * @brief Prints all elements and count of the list to stdout.
 *
 * @param list Pointer to the list structure.
 */
void list_log(list_t *list);

/**
 * @brief Returns a newly allocated array containing all list elements.
 *
 * The caller is responsible for freeing the returned array.
 *
 * @param list Pointer to the list structure.
 * @return Pointer to a dynamically allocated array of integers.
 */
int* list_get_items(list_t *list);

/**
 * @brief Checks if an element exists in the list.
 *
 * @param list Pointer to the list structure.
 * @param elem Integer value to search for.
 * @return 1 (true) if found, 0 (false) otherwise.
 */
int list_exist_elem(list_t *list, int elem);

/**
 * @brief Gets the element at the specified index (1-based).
 *
 * @param list Pointer to the list structure.
 * @param index 1-based position in the list.
 * @return The value at the index, or -1 if index is out of bounds.
 */
int list_get_elem(list_t *list, int index);

/**
 * @brief Adds a node to a circular list starting from root.
 *
 * @param n1 Pointer to the root node.
 * @param n2 Pointer to the node to insert.
 */
void add_node(node_t *n1, node_t *n2);

/**
 * @brief Adds a new node at the end of the circular list.
 *
 * @param init Pointer to the head node of the list.
 * @param new_node Pointer to the node to append.
 */
void add_end(node_t* init, node_t* new_node);

/**
 * @brief Deletes the first node with the given value from a circular list.
 *
 * @param root Pointer to the head node.
 * @param value Integer value to search for and delete.
 */
void delete_node(node_t *root, int value);

/**
 * @brief Searches for a value in the list and prints its position.
 *
 * @param list Pointer to the list structure.
 * @param value Integer value to search for.
 */
void list_search(list_t *list, int value);

/**
 * @brief Prints all values in the circular list.
 *
 * @param last Pointer to the last node (whose next points to head).
 */
void print_list(node_t *last);

/**
 * @brief Frees all memory associated with the list and its container.
 *
 * @param list Pointer to the list structure to destroy.
 */
void del_list(list_t *list);

/**
 * @brief Frees all nodes in a circular list starting from the given element.
 *
 * @param elem Pointer to any node in the circular list.
 */
void delete_list(node_t* elem);

/**
 * @brief Prints a node's value and next pointer address with a tag.
 *
 * @param node Pointer to the node to log.
 * @param tag Label string to prefix the output.
 */
void log_node(node_t *node, const char *tag);
