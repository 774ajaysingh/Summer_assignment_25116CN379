/*Write a program to Check anagram strings. */

#include <stdio.h>
int main() {    
    
    char str1[100], str2[100];
    int freq1[256] = {0}, freq2[256] = {0};
    int i, l1, l2;

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    l1 = strlen(str1);
    l2 = strlen(str2);

    if (l1 != l2) {
        printf("Strings are not anagrams.\n");
        return 0;
    }

    for (i = 0; i < l1; i++) {
        freq1[str1[i]]++;
        freq2[str2[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (freq1[i] != freq2[i]) {
            printf("Strings are not anagrams.\n");
            return 0;
        }
    }

    printf("Strings are anagrams.\n");
    return 0;
}