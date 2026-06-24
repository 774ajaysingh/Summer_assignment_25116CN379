/*Write a program to Compress a string. */
#include <stdio.h>
#include <string.h>
int main() {
    char str[100], compressed[200];
    int i, j = 0, count;

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (i = 0; i < len; i++) {
        count = 1;

        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        compressed[j++] = str[i];
        j += sprintf(&compressed[j], "%d", count);
    }

    compressed[j] = '\0';

    printf("Compressed string: %s\n", compressed);

    return 0;