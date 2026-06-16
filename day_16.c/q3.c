/*Write a program to Find pair with given sum.*/

#include <stdio.h>

int main() {
    int n, sum, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter required sum: ");
    scanf("%d", &sum);

    int found = 0;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == sum) {
                printf("Pair found: %d + %d = %d\n", arr[i], arr[j], sum);
                found = 1;
            }
        }
    }

    if(found == 0) {
        printf("oops No pair found.");
    }

    return 0;
}