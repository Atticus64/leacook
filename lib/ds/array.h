#include <stdlib.h>
#include <stdio.h>

/**
 * @file array.h
 * @brief Dynamic array of integers with automatic resizing.
 *
 * This module implements a dynamic array (Nums) that stores integers.
 * The array automatically doubles its capacity when it becomes full.
 */

/**
 * @struct Nums
 * @brief Dynamic array structure for storing integers.
 */
typedef struct {
	int *items;     /**< Pointer to the array of integers */
	size_t count;   /**< Current number of elements in the array */
	size_t capacity; /**< Current allocated capacity of the array */
} Nums;

/**
 * @brief Creates a new dynamic array with the specified capacity.
 *
 * @param capacity Initial capacity of the array (must be > 0).
 * @return Pointer to the newly created Nums structure, or NULL if capacity < 1.
 */
Nums* new_array(size_t capacity);

/**
 * @brief Prints all elements of the array to stdout.
 *
 * @param list Pointer to the Nums structure to display.
 */
void show_array(Nums* list);

/**
 * @brief Appends a new integer to the end of the array.
 *
 * If the array is full, it automatically resizes by doubling its capacity.
 *
 * @param num The integer value to append.
 * @param list Pointer to the Nums structure.
 */
void array_append(int num, Nums* list);

/**
 * @brief Frees all memory associated with the array.
 *
 * @param list Pointer to the Nums structure to destroy.
 */
void del_array(Nums* list);
