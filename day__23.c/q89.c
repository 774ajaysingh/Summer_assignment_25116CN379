/*Write a program to Find first non-repeating 
character. */
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int i, l;

    printf("Enter a string: ");
    gets(str);

    l = strlen(str);
    for (i = 0; i < l; i++) {
        freq[str[i]]++;
    }
    for (i = 0; i < l; i++) {
        if (freq[str[i]] == 1) {
            printf("First non-repeating character is: %c\n", str[i]);
            break;
        }
    }

    return 0;
}