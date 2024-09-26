#include <stdio.h>

int lower(int c) {

    if ( c >= 'A' || c <= 'Z') {
        return c - 32;
    } 

    return c;
}

int val_hxchar(char arg) {

    if ( arg >= '0' && arg <= '9') {
        return arg - '0';
    }

    arg = lower(arg);

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

int from_hex(char hex[]) {
    int val = 0;

    for (int i = 0; hex[i] >= '0' && hex[i] <= '9' || is_letter(hex[i]) ; ++i)  {
        val = val * 16 + (val_hxchar(hex[i]));
    }

    return val;
}


int hex_app() {
    char hex[40] = "";

    printf("Enter an input: ");
    if (fgets(hex, 40, stdin))
    {
        printf("hex val %s", hex);
        printf("int value -> %d\n", from_hex(hex));
    }


    return 0;
}
