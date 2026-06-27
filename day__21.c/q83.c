/*Write a program to Count vowels and 
consonants. */
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, v = 0, c = 0;

printf("Enter a string: ");
fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
                v++;
            } else {
                c++;
            }
        }
    }

    printf("Number of vowels: %d\n", v);
    printf("Number of consonants: %d\n", c);

    return 0;
}
