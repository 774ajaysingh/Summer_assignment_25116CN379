/**/
#include <stdio.h>
#include <string.h>

int main() {
    char str[200], longest[50];
    int i, len = 0, maxLen = 0, start = 0, maxStart = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            len++;
        } else {
            if (len > maxLen) {
                maxLen = len;
                maxStart = start;
            }
            len = 0;
            start = i + 1;
        }
    }

    if (len > maxLen) {
        maxLen = len;
        maxStart = start;
    }

    strncpy(longest, str + maxStart, maxLen);
    longest[maxLen] = '\0';

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", maxLen);

    return 0;
}