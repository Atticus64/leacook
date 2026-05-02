/**
 * @file hex.h
 * @brief Hexadecimal conversion utilities.
 *
 * This module provides functions for converting hexadecimal strings
 * to integers and manipulating character case.
 */

/**
 * @brief Interactive application that reads a hex string from stdin
 *        and prints its integer equivalent.
 *
 * @return 0 on success.
 */
int hex_app();

/**
 * @brief Converts a single hexadecimal character to its integer value.
 *
 * Accepts '0'-'9', 'a'-'f', 'A'-'F'. Returns 0 for invalid characters.
 *
 * @param arg Hexadecimal character to convert.
 * @return Integer value (0-15) corresponding to the hex character.
 */
int val_hxchar(char arg);

/**
 * @brief Converts a lowercase letter to its uppercase equivalent.
 *
 * @param c Character to be converted.
 * @return Uppercase character if input is lowercase, otherwise returns the same character.
 */
int upper(int c);

/**
 * @brief Converts a hexadecimal string to its integer equivalent.
 *
 * Processes characters until a non-hex character is encountered.
 *
 * @param hex String containing the hexadecimal value.
 * @return Integer equivalent of the hexadecimal string.
 */
int from_hex(char hex[]);

/**
 * @brief Checks if a character is an alphabetic letter.
 *
 * @param c Character to check.
 * @return 1 if the character is 'a'-'z' or 'A'-'Z', 0 otherwise.
 */
int is_letter(char c);
