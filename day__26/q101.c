/*Write a program to Create number guessing 
game*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess;
    srand(time(0));
    secretNumber = rand() % 100 + 1;
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Try to guess it!\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d correctly.\n", secretNumber);
        }
    } while (guess != secretNumber);

    return 0;
}