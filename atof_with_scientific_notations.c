//* gcc -o output atof_with_scientific_notations.c && output

#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAXLINE 100

double atof(char s[]);

int main(void) {
    // rudimentary calculator:
    double sum, atof(char s[]);
    char line[MAXLINE];
    int mygetline(char line[], int max);

    sum = 0;
    while (mygetline(line, MAXLINE) > 0) {
        printf("\t%g\n", atof(line));
    }

    return 0;
}

int mygetline(char s[], int lim) {
    int c, i;

    for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
        s[i] = c;

    if (c == '\n') {

        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

double atof(char s[]) {
    double val, power;
    int i, sign, sientific_sign, sientific_number;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;

    // for sign:
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    // for value:
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // 1 - for decimal point:
    if (s[i] == '.')
        i++;
    // 2 - for decimal number:
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }


    // for scientific notation:
    if (s[i] == 'e' || s[i] == 'E') {
        printf("e found\n");
        i++;
        // if we have -ve sign, increase i again:
        sientific_sign = (s[i] == '-') ? -1, i++ : 1;

        for (sientific_number = 0; isdigit(s[i]); i++)
            sientific_number = 10 * sientific_number + (s[i] - '0');

        sientific_number *= sientific_sign;
        return sign * (val / power) * pow(10, sientific_number);
    }

        return sign * (val / power);
    }
