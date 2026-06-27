/*Write a program to Subtract matrices*/

#include <stdio.h>

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r, c, i, j;

printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

printf("Enter elements of first matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

printf("Enter elements of second matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
        }
    }

for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
printf("Resultant matrix after subtraction:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
