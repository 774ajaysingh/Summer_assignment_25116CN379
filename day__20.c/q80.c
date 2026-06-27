/*Write a program to Find row-wise sum.*/
#include <stdio.h>

int main() {
    int a[10][10], r, c, i, j;
    int sum;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Row-wise sums:\n");
    for (i = 0; i < r; i++) {
        sum = 0;
        for (j = 0; j < c; j++) {
            sum += a[i][j];
        }
        printf("Sum of row %d: %d\n", i + 1, sum);
    }

    return 0;
}