#include "../ds/stack.h"

typedef enum {
	L_PAREN,
	R_PAREN,
	SYMBOL,
	PLUS,
	MINUS,
	INT,
	FLOAT
} t_type;

typedef struct Token {
	t_type type;
	char* value[60];
} t_token;

t_type check_lexema(char lexema);

void check_program(char* input, stack_t* st); 


