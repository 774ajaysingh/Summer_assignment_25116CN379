/*Write a program to Create menu-driven array 
operations system*/
#include <stdio.h>

int main() {
    int arr[100], n = 0;
    int choice, i, element, found = 0;
    int max, min;

    do {
        printf("\n===== MENU-DRIVEN ARRAY OPERATIONS =====\n");
        printf("1. Insert Elements\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");
        printf("4. Find Largest Element\n");
        printf("5. Find Smallest Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array Elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Enter element to search: ");
                    scanf("%d", &element);
                    found = 0;
                    for (i = 0; i < n; i++) {
                        if (arr[i] == element) {
                            printf("Element found at position %d\n", i + 1);
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                        printf("Element not found.\n");
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    max = arr[0];
                    for (i = 1; i < n; i++) {
                        if (arr[i] > max)
                            max = arr[i];
                    }
                    printf("Largest element = %d\n", max);
                }
                break;

            case 5:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    min = arr[0];
                    for (i = 1; i < n; i++) {
                        if (arr[i] < min)
                            min = arr[i];
                    }
                    printf("Smallest element = %d\n", min);
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}