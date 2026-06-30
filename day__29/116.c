#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

struct Item {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int findItemById(struct Item items[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            return i;
        }
    }
    return -1;
}

void displayItem(const struct Item *item) {
    printf("ID: %d\n", item->id);
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);
}

void displayAllItems(const struct Item items[], int count) {
    if (count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\nInventory List:\n");
    for (int i = 0; i < count; i++) {
        printf("--------------------------\n");
        displayItem(&items[i]);
    }
    printf("--------------------------\n");
}

int main(void) {
    struct Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("1. Add item\n");
        printf("2. Display all items\n");
        printf("3. Update item quantity\n");
        printf("4. Delete item\n");
        printf("5. Search item by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                if (itemCount >= MAX_ITEMS) {
                    printf("Inventory is full. Cannot add more items.\n");
                    break;
                }
                printf("Enter item ID: ");
                scanf("%d", &items[itemCount].id);
                while (getchar() != '\n');
                if (findItemById(items, itemCount, items[itemCount].id) != -1) {
                    printf("Item with this ID already exists.\n");
                    break;
                }
                printf("Enter item name: ");
                readLine(items[itemCount].name, NAME_LENGTH);
                printf("Enter quantity: ");
                scanf("%d", &items[itemCount].quantity);
                while (getchar() != '\n');
                printf("Enter price: ");
                scanf("%f", &items[itemCount].price);
                while (getchar() != '\n');
                itemCount++;
                printf("Item added successfully.\n");
                break;
            case 2:
                displayAllItems(items, itemCount);
                break;
            case 3:
                if (itemCount == 0) {
                    printf("Inventory is empty.\n");
                    break;
                }
                printf("Enter item ID to update: ");
                int updateId;
                scanf("%d", &updateId);
                while (getchar() != '\n');
                {
                    int index = findItemById(items, itemCount, updateId);
                    if (index == -1) {
                        printf("Item not found.\n");
                    } else {
                        printf("Enter new quantity: ");
                        scanf("%d", &items[index].quantity);
                        while (getchar() != '\n');
                        printf("Quantity updated successfully.\n");
                    }
                }
                break;
            case 4:
                if (itemCount == 0) {
                    printf("Inventory is empty.\n");
                    break;
                }
                printf("Enter item ID to delete: ");
                int deleteId;
                scanf("%d", &deleteId);
                while (getchar() != '\n');
                {
                    int index = findItemById(items, itemCount, deleteId);
                    if (index == -1) {
                        printf("Item not found.\n");
                    } else {
                        for (int i = index; i < itemCount - 1; i++) {
                            items[i] = items[i + 1];
                        }
                        itemCount--;
                        printf("Item deleted successfully.\n");
                    }
                }
                break;
            case 5:
                if (itemCount == 0) {
                    printf("Inventory is empty.\n");
                    break;
                }
                printf("Enter item ID to search: ");
                int searchId;
                scanf("%d", &searchId);
                while (getchar() != '\n');
                {
                    int index = findItemById(items, itemCount, searchId);
                    if (index == -1) {
                        printf("Item not found.\n");
                    } else {
                        displayItem(&items[index]);
                    }
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
