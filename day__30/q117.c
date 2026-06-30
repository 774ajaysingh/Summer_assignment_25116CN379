/*Write a program to Create student record
system using arrays and strings.*/
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define CLASS_LENGTH 20

struct Student {
    int id;
    char name[NAME_LENGTH];
    char className[CLASS_LENGTH];
    float marks;
};

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int findStudentById(const struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void displayStudent(const struct Student *student) {
    printf("ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Class: %s\n", student->className);
    printf("Marks: %.2f\n", student->marks);
}

void displayAllStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("---------------------------\n");
        displayStudent(&students[i]);
    }
    printf("---------------------------\n");
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\nStudent Record System\n");
        printf("1. Add student record\n");
        printf("2. Display all student records\n");
        printf("3. Search student by ID\n");
        printf("4. Update student marks\n");
        printf("5. Delete student record\n");
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
                if (studentCount >= MAX_STUDENTS) {
                    printf("Maximum student limit reached.\n");
                    break;
                }
                printf("Enter student ID: ");
                scanf("%d", &students[studentCount].id);
                while (getchar() != '\n');
                if (findStudentById(students, studentCount, students[studentCount].id) != -1) {
                    printf("Student with this ID already exists.\n");
                    break;
                }
                printf("Enter student name: ");
                readLine(students[studentCount].name, NAME_LENGTH);
                printf("Enter class: ");
                readLine(students[studentCount].className, CLASS_LENGTH);
                printf("Enter marks: ");
                scanf("%f", &students[studentCount].marks);
                while (getchar() != '\n');
                studentCount++;
                printf("Student record added successfully.\n");
                break;
            case 2:
                displayAllStudents(students, studentCount);
                break;
            case 3:
                if (studentCount == 0) {
                    printf("No student records available.\n");
                    break;
                }
                printf("Enter student ID to search: ");
                {
                    int searchId;
                    scanf("%d", &searchId);
                    while (getchar() != '\n');
                    int index = findStudentById(students, studentCount, searchId);
                    if (index == -1) {
                        printf("Student not found.\n");
                    } else {
                        displayStudent(&students[index]);
                    }
                }
                break;
            case 4:
                if (studentCount == 0) {
                    printf("No student records available.\n");
                    break;
                }
                printf("Enter student ID to update marks: ");
                {
                    int updateId;
                    scanf("%d", &updateId);
                    while (getchar() != '\n');
                    int index = findStudentById(students, studentCount, updateId);
                    if (index == -1) {
                        printf("Student not found.\n");
                    } else {
                        printf("Enter new marks: ");
                        scanf("%f", &students[index].marks);
                        while (getchar() != '\n');
                        printf("Marks updated successfully.\n");
                    }
                }
                break;
            case 5:
                if (studentCount == 0) {
                    printf("No student records available.\n");
                    break;
                }
                printf("Enter student ID to delete: ");
                {
                    int deleteId;
                    scanf("%d", &deleteId);
                    while (getchar() != '\n');
                    int index = findStudentById(students, studentCount, deleteId);
                    if (index == -1) {
                        printf("Student not found.\n");
                    } else {
                        for (int i = index; i < studentCount - 1; i++) {
                            students[i] = students[i + 1];
                        }
                        studentCount--;
                        printf("Student record deleted successfully.\n");
                    }
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

