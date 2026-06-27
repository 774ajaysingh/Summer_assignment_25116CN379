/*Write a program to Count words in a 
sentence. */
#include <stdio.h>

int main() {
    char str[100];
    int i, words = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            words++;
        }
    }
    words++;

    printf("Number of words: %d\n", words);

    return 0;
}
