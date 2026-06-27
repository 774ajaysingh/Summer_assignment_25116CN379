/*Write a program to Find maximum occurring 
character.*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int i, l, max_freq = 0;
    char max_char;

    printf("Enter a string: ");
    gets(str);

    l = strlen(str);
    for (i = 0; i < l; i++) {
        freq[str[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_char = i;
        }
    }

    printf("Maximum occurring character is: %c\n", max_char);
    return 0;
}