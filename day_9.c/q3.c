/*Write a program to Print repeated character 
pattern. 
A 
BB 
CCC 
DDDD 
EEEEE */

#include <stdio.h>

int main() {
    int i, j,n;
    printf("enter the no. of rows:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("%c", 'A' + i - 1);
        }
        printf("\n");
    }

    return 0;
}