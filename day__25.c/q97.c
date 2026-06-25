/*Write a program to Merge two sorted arrays. */
#include <stdio.h>
#define MAX_SIZE 100
int main() {
   int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE * 2];
   int size1, size2, mergedSize;
   int i, j, temp;

   do {
       printf("Enter the size of first array (must be > 0): ");
       scanf("%d", &size1);
   } while (size1 <= 0);

   printf("Enter elements in first array: ");
   for (i = 0; i < size1; i++) {
       scanf("%d", &arr1[i]);
   }

   do {
       printf("Enter the size of second array (must be > 0): ");
       scanf("%d", &size2);
   } while (size2 <= 0);

   printf("Enter elements in second array: ");
   for (i = 0; i < size2; i++) {
       scanf("%d", &arr2[i]);
   }
  
   mergedSize = size1 + size2;
   for (i = 0; i < size1; i++) {
       merged[i] = arr1[i];
   }
   for (i = 0; i < size2; i++) {
       merged[size1 + i] = arr2[i];
   }

   for (i = 0; i < mergedSize - 1; i++) {
       for (j = i + 1; j < mergedSize; j++) {
           if (merged[i] > merged[j]) {
               temp = merged[i];
               merged[i] = merged[j];
               merged[j] = temp;
           }
       }
   }

   printf("Merged array in ascending order: ");
   for (i = 0; i < mergedSize; i++) {
       printf("%d ", merged[i]);
   }
   return 0;
}