/**Write a program to Create menu-driven 
string operations system*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int countVowels(const char *s) {
    int count = 0;
    while (*s) {
        char c = tolower((unsigned char)*s);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        s++;
    }
    return count;
}

void reverseString(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

int main(void) {
    char str1[200];
    char str2[200];
    int choice;

    printf("Enter the first string:\n");
    readLine(str1, sizeof(str1));

    do {
        printf("\nString Operations Menu:\n");
        printf("1. Display string\n");
        printf("2. Length of string\n");
        printf("3. Copy string\n");
        printf("4. Concatenate string\n");
        printf("5. Compare string\n");
        printf("6. Reverse string\n");
        printf("7. Count vowels\n");
        printf("8. Search substring\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Current string: %s\n", str1);
                break;
            case 2:
                printf("Length: %zu\n", strlen(str1));
                break;
            case 3:
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
            case 4:
                printf("Enter string to concatenate: \n");
                readLine(str2, sizeof(str2));
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated string: %s\n", str1);
                } else {
                    printf("Result would exceed buffer size. Operation aborted.\n");
                }
                break;
            case 5:
                printf("Enter string to compare with: \n");
                readLine(str2, sizeof(str2));
                {
                    int cmp = strcmp(str1, str2);
                    if (cmp == 0) {
                        printf("Strings are equal.\n");
                    } else if (cmp < 0) {
                        printf("First string is less than second string.\n");
                    } else {
                        printf("First string is greater than second string.\n");
                    }
                }
                break;
            case 6:
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;
            case 7:
                printf("Number of vowels: %d\n", countVowels(str1));
                break;
            case 8:
                printf("Enter substring to search: \n");
                readLine(str2, sizeof(str2));
                if (strstr(str1, str2)) {
                    printf("Substring found.\n");
                } else {
                    printf("Substring not found.\n");
                }
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 9);

    return 0;
}
