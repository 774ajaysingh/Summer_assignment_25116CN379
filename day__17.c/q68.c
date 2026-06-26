/*Write a program to Find common elements. */

#include <stdio.h>
int main (){
    int arr1[100], arr2[100], common[100];
    int a1, a2, i, j, k=0;

    printf ("Enter the size of first array: ");
    scanf ("%d", &a1);

    printf ("Enter the size of second array: ");
    scanf ("%d", &a2);

    printf ("Enter the elements of first array: ");
    for (i = 0; i < a1; i++){
        scanf ("%d", &arr1[i]);
    }

    printf ("Enter the elements of second array: ");
    for (i = 0; i < a2; i++){
        scanf ("%d", &arr2[i]);
    }

    for(i = 0; i < a1; i++) {
        for(j = 0; j < a2; j++) {
            if(arr1[i] == arr2[j]) {
                common[k++] = arr1[i];
                break;
            }
        }
    }

    printf("Common elements: ");
    for(i = 0; i < k; i++) {
        printf("%d ", common[i]);
    }

    return 0;
}