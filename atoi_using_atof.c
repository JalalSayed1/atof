//* gcc -o output atoi_using_atof.c && output

#include <stdio.h>

int atoi(char s[]);

int main(void) {

    // test atoi:
    char s[] = "12345";
    printf("%d\n", atoi(s));

    return 0;
}

int atoi(char s[]) {
    double atof(char s[]);

    // cast result here to show that this action is intended to be done and suppress any compiler warnings:
    return (int) atof(s);
}
