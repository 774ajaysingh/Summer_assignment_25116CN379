/*Write a program to Print character pyramid. Microsoft, Adobe, Paytm 
      A 
   ABA 
  ABCBA 
 ABCDCBA 
ABCDEDCBA */


#include <stdio.h>

int main() {
    int i, j, space;
    int n ;

    printf("enter the number of rows:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {

      
        for(space = 1; space <= n - i; space++) {
            printf(" ");
        }

        for(j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }

        for(j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }

        printf("\n");
    }

    return 0;
}