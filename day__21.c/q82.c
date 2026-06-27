/*Write a program to Reverse a string.*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int length, i;
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    length = strlen(s) - 1; 

    printf("Reversed string is: ");
    for (i = length; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
