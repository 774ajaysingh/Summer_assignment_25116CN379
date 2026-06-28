/*Write a program to Create bank account 
system*/
#include <stdio.h>

int main() {
    int choice;
    float balance = 1000.0, amount;

    printf("Welcome to the Bank Account System\n");

    do {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your current balance is: %.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful. New balance: %.2f\n", balance);
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Withdrawal successful. New balance: %.2f\n", balance);
                } else {
                    printf("Insufficient balance or invalid amount.\n");
                }
                break;
            case 4:
                printf("Thank you for using the bank account system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
