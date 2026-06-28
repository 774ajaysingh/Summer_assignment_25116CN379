/*Write a program to Create quiz application.*/
#include <stdio.h>

int main() {
    int score = 0;
    char answer;

    printf("Welcome to the Quiz Application!\n");
    printf("Answer with A, B, C, or D.\n\n");

    printf("1. What is the capital of France?\n");
    printf("A. London\nB. Paris\nC. Rome\nD. Berlin\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') score++;

    printf("\n2. Which language is used for this program?\n");
    printf("A. Java\nB. Python\nC. C\nD. C++\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') score++;

    printf("\n3. What is 2 + 2?\n");
    printf("A. 3\nB. 4\nC. 5\nD. 6\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') score++;

    printf("\nQuiz completed!\n");
    printf("Your score is: %d/3\n", score);

    if (score == 3) {
        printf("Excellent! You got all answers correct.\n");
    } else if (score >= 2) {
        printf("Good job!\n");
    } else {
        printf("Try again and improve your score.\n");
    }

    return 0;
}
