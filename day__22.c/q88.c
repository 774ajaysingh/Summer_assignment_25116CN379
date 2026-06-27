/*Write a program to Remove spaces from 
string. */
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] == ' '; i++);
    if (i > 0) {
        for (j = 0; str[i] != '\0'; i++, j++) {
            str[j] = str[i];
        }
        str[j] = '\0';
    }

    for (i = strlen(str) - 1; i >= 0 && str[i] == ' '; i--);
    str[i + 1] = '\0';

    printf("String after removing spaces: %s\n", str);

    return 0;
}
