/*Write a program to Find missing number in 
array. */

#include <stdio.h>
#include <stdlib.h>
int main () {

    int n,i;
    printf ("enter a value of n: ");
    scanf("%d",&n);

    int *arr = malloc((n - 1) * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    

    printf("enter %d number : \n",n-1);
    for(i = 0;i < n-1;i++){
        scanf("%d",&arr[i]);

    }
    
    int total_sum = n * (n + 1) / 2;
    int array_sum = 0;

    for(i = 0; i < n - 1; i++) {
        array_sum += arr[i];
    }

    int missing = total_sum - array_sum;

    printf("Missing number = %d\n", missing);

    return 0;
}