/*Write a program to Rotate array right.*/

#include <stdio.h>

int main() {
    int n, i;
    int arr[150], l;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    l = arr[n - 1];

    for(i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = l;

    printf("Array after right rotation:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}