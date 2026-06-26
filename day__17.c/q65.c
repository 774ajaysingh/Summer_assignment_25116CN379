/*Write a program to Merge arrays. */

#include <stdio.h> 
int main (){
    int arr1[100], arr2[100], merged[200];
    int a1 ,a2 ,i ,j;

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
    for (i = 0; i < a1; i++){
        merged[i] = arr1[i];
    }
    for (i = 0; i < a2; i++){
        merged[a1 + i] = arr2[i];
    }
    printf ("Merged array: ");
    for (i = 0; i < a1 + a2; i++){
        printf ("%d ", merged[i]);
    }
    return 0;
}