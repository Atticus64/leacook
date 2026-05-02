#include "../ds/stack.h"

/**
 * @file lexer.h
 * @brief Lexical analyzer for simple arithmetic expressions.
 *
 * This module implements a basic lexer that tokenizes characters into
 * token types (parentheses, operators, numbers, symbols) and uses
 * a stack-based automaton to validate parenthesis matching.
 */

/**
 * @enum t_type
 * @brief Token types recognized by the lexer.
 */
typedef enum {
	L_PAREN,    /**< Left parenthesis '(' */
	R_PAREN,    /**< Right parenthesis ')' */
	SYMBOL,     /**< Alphabetic or other symbol character */
	PLUS,       /**< Plus operator '+' */
	MINUS,      /**< Minus operator '-' */
	INT,        /**< Integer digit '0'-'9' */
	FLOAT       /**< Floating point number (reserved) */
} t_type;

/**
 * @struct Token
 * @brief Represents a lexical token with its type and value.
 */
typedef struct Token {
	t_type type;        /**< Type of the token */
	char* value[60];    /**< Value associated with the token */
} t_token;

/**
 * @brief Classifies a single character into its token type.
 *
 * @param lexema Character to classify.
 * @return The corresponding t_type enum value.
 */
t_type check_lexema(char lexema);

/**
 * @brief Validates parenthesis matching in an input string using a stack automaton.
 *
 * Pushes onto the stack for each '(' and pops for each ')'.
 * Prints each character with its token type during processing.
 *
 * @param input Null-terminated string to analyze.
 * @param st Pointer to the stack used for parenthesis tracking.
 */
void check_program(char* input, stack_t* st);
