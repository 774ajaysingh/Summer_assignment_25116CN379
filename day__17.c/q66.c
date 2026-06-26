/*Write a program to Union of arrays*/

#include <stdio.h>
int main (){
     int arr1[100], arr2[100], unionarray[200];
    int a1, a2, i, j,k=0 ,flag;

    printf ("Enter the size of first array: ");
    scanf ("%d", &a1);

    printf ("Enter the size of second array: ");
    scanf ("%d", &a2);

    printf ("Enter the elements of first array: ");
    for (i = 0; i < a1; i++){
        scanf ("%d", &arr1[i]);
        unionarray[k++] = arr1[i];
    }

    printf ("Enter the elements of second array: ");
    for (i = 0; i < a2; i++){

        scanf ("%d", &arr2[i]);

    }
 for(i = 0; i < a2; i++) {
        flag = 0;
        for(j = 0; j < k; j++) {
            if(arr2[i] == unionarray[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            unionarray[k++] = arr2[i];
        }
    }

    printf("Union of arrays: ");
    for(i = 0; i < k; i++) {
        printf("%d ", unionarray[i]);
    }

    return 0;