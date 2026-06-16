/*Write a program to Find maximum frequency 
element. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    
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

    int maxFreq = 0, maxElement;

    for(i = 0; i < n; i++) {
        int freq = 1;

        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                freq++;
            }
        }

        if(freq > maxFreq) {
            maxFreq = freq;
            maxElement = arr[i];
        }
    }

    printf("Maximum frequency element = %d\n", maxElement);
    printf("Frequency = %d\n", maxFreq);

    return 0;
}