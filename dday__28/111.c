/*Write a program to Create ticket booking 
system.*/
#include <stdio.h>

int main() {
    int choice, tickets;
    float price = 150.0;

    printf("Welcome to the Ticket Booking System\n");
    printf("1. Book Ticket\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter number of tickets: ");
        scanf("%d", &tickets);

        if (tickets > 0) {
            printf("Booking successful!\n");
            printf("Total amount: %.2f\n", tickets * price);
            printf("Enjoy your trip.\n");
        } else {
            printf("Invalid number of tickets.\n");
        }
    } else if (choice == 2) {
        printf("Thank you for visiting.\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
