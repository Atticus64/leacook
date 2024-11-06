#include <stdio.h>

/**
 * Convert a lowercase letter to its uppercase equivalent.
 * 
 * @param c Character to be converted.
 * @return Uppercase character if input is lowercase, otherwise returns the same character.
 */
int upper(int c) {

    if ( c >= 'a' && c <= 'z') {
        return c - 32;
    } 

    return c;
}

/**
 * Convert a hexadecimal character to its integer value.
 * 
 * @param arg Hexadecimal character ('0'-'9', 'a'-'f', 'A'-'F').
 * @return Corresponding integer value of the hexadecimal character.
 */
int val_hxchar(char arg) {

    if ( arg >= '0' && arg <= '9') {
        return arg - '0';
    }

    arg = upper(arg);

    switch(arg) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        default:
            return 0;
    }
}

int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * Convert a hexadecimal string to an integer.
 * 
 * @param hex String containing the hexadecimal value.
 * @return Integer equivalent of the hexadecimal string.
 */
int from_hex(char hex[]) {
    int val = 0;

    for (int i = 0; hex[i] >= '0' && hex[i] <= '9' || is_letter(hex[i]) ; ++i)  {
        val = val * 16 + (val_hxchar(hex[i]));
    }

    return val;
}


int hex_app() {
    char hex[40] = "";
	char letter = 'a';
	letter += 2;
	printf("valor letra: %d\n", letter);
	printf("letra: %c\n", letter);
    printf("Enter an input: ");
    if (fgets(hex, 40, stdin))
    {
        printf("hex val %s", hex);
        printf("int value -> %d\n", from_hex(hex));
    }


    return 0;
}
