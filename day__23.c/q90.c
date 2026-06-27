/*Write a program to Find first repeating 
character. */

#include <stdio.h>
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
        if (freq[str[i]] > 1) {
            printf("First repeating character is: %c\n", str[i]);
            break;
        }
    }

    return 0;
}