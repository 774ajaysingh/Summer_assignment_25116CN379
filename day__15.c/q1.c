/*Write a program to Reverse array. */

#include <stdio.h>

int main() {
    int n, i, tempO;
    int arr[150];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n / 2; i++) {
        tempO = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tempO;
    }

    printf("Reversed array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}