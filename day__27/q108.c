/*Write a program to Create marksheet 
generation system. */
#include <stdio.h>

int main() {
    char name[50];
    int roll, marks[5];
    int i, total = 0;
    float percentage;

    printf("Enter student name: ");
    scanf("%s", name);

    printf("Enter roll number: ");
    scanf("%d", &roll);

    printf("Enter marks of 5 subjects:\n");
    for (i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];
    }

    percentage = total / 5.0;

    printf("\n========== MARKSHEET ==========");
    printf("\nName: %s", name);
    printf("\nRoll Number: %d", roll);
    printf("\n------------------------------");
    for (i = 0; i < 5; i++) {
        printf("\nSubject %d: %d", i + 1, marks[i]);
    }
    printf("\n------------------------------");
    printf("\nTotal Marks: %d", total);
    printf("\nPercentage: %.2f%%", percentage);

    if (percentage >= 90) {
        printf("\nGrade: A+");
    } else if (percentage >= 80) {
        printf("\nGrade: A");
    } else if (percentage >= 70) {
        printf("\nGrade: B");
    } else if (percentage >= 60) {
        printf("\nGrade: C");
    } else if (percentage >= 50) {
        printf("\nGrade: D");
    } else {
        printf("\nGrade: F");
    }

    printf("\n==============================\n");
    return 0;
}
