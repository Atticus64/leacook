
/**
 * @file str.h
 * @brief String manipulation utilities.
 *
 * This module provides manual implementations of common string operations
 * such as length calculation and concatenation.
 */

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * Counts characters until the null terminator '\0' is found.
 *
 * @param str Pointer to the null-terminated string.
 * @return Number of characters in the string (excluding null terminator).
 */
int len(char* str);

/**
 * @brief Concatenates str2 to the end of str1.
 *
 * Appends all characters from str2 (excluding null terminator) to str1.
 * Note: str1 must have sufficient buffer space to hold the result.
 *
 * @param str1 Destination string (must have enough space).
 * @param str2 Source string to append.
 */
void cat(char* str1, char* str2);
