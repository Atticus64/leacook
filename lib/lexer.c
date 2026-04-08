#include <stdio.h>
#include "./lexer.h"

t_type check_lexema(char lexema) {
	if (lexema == '(') {
		return L_PAREN;
	}

	if (lexema == ')') {
		return R_PAREN;
	}

	if (lexema >= '0' && lexema <= '9') {
		return INT;
	}

	if (lexema == '+') {
		return PLUS;
	}

	if (lexema == '-') {
		return MINUS;
	}
	
	return SYMBOL;
}

char* lexema_str(t_type t) {
	switch (t) {
		case R_PAREN:
			return "R_PAREN";
		case L_PAREN:
			return "L_PAREN";
		case SYMBOL:
			return "SYMBOL";
		case MINUS:
			return "MINUS";
		case PLUS:
			return "PLUS";
		case INT: 
			return "INT";
		case FLOAT:
			return "FLOAT";
		default: 
			return "NIL";
	}
}

void check_program(char* input, stack_t* st) {

	int i = 0;
	char ch = input[i];
	while (ch != '\0') {
		t_type t_lex = check_lexema(ch);

		if (t_lex == L_PAREN) {
			push(st, '1');
		} else if (t_lex == R_PAREN) {
			pop(st, '1', i);
		}
		printf("c => %c [%s]\n", ch, lexema_str(t_lex));
		i++;
		ch = input[i];
	}

	pop(st, 'Z', i);

}


