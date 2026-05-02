/**
 * @file stack.h
 * @brief Stack (LIFO) data structure for characters.
 *
 * This module implements a stack using a linked list of elements.
 * It supports standard push/pop operations and includes special
 * automaton_push/automaton_pop functions for parenthesis validation.
 */

/**
 * @struct Elem
 * @brief A single element in the stack.
 */
typedef struct Elem elem_t;

typedef struct Elem {
	char value;     /**< Character value stored in this element */
	elem_t* next;   /**< Pointer to the next element below in the stack */
} elem_t;

/**
 * @struct Stack
 * @brief Container structure for the stack.
 */
typedef struct Stack {
	int count;      /**< Number of elements in the stack */
	elem_t* top;    /**< Pointer to the top element of the stack */
} stack_t;

/**
 * @brief Creates a new empty stack with a sentinel element.
 *
 * @return Pointer to the newly created stack.
 */
stack_t* create_stack();

/**
 * @brief Pushes a character onto the top of the stack.
 *
 * @param stack Pointer to the stack structure.
 * @param elem Character value to push.
 */
void push(stack_t* stack, char elem);

/**
 * @brief Returns the character at the top of the stack without removing it.
 *
 * @param stack Pointer to the stack structure.
 * @return The character value at the top.
 */
char peek(stack_t* stack);

/**
 * @brief Removes and returns the character at the top of the stack.
 *
 * @param stack Pointer to the stack structure.
 * @return The character value that was removed.
 */
char pop(stack_t* stack);

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack Pointer to the stack structure.
 * @return 1 if empty (count <= 0), 0 otherwise.
 */
int empty_stack(stack_t* stack);

/**
 * @brief Pushes a character onto the stack (automaton variant).
 *
 * This variant appends to the end of the linked list rather than the top.
 * Used for parenthesis matching automaton.
 *
 * @param stack Pointer to the stack structure.
 * @param elem Character value to push.
 */
void automaton_push(stack_t* stack, char elem);

/**
 * @brief Pops a character from the end of the stack (automaton variant).
 *
 * Validates that the expected character matches before removing.
 * Prints an error message if the expected character is not found.
 *
 * @param stack Pointer to the stack structure.
 * @param elem Expected character value to pop.
 * @param position Position in the input string (for error reporting).
 */
void automaton_pop(stack_t* stack, char elem, int position);

/**
 * @brief Prints all elements of the stack to stdout.
 *
 * @param stack Pointer to the stack structure.
 */
void show_stack(stack_t* stack);

/**
 * @brief Frees all memory associated with the stack.
 *
 * @param stack Pointer to the stack structure to destroy.
 */
void del_stack(stack_t* stack);
