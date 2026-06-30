/*Write a program to Develop complete mini 
project using arrays, strings and functions. */
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int roll;
    char name[50];
    float marks;
};

struct Student s[MAX];
int count = 0;
void addStudent()
{
    printf("Enter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student Added Successfully!\n");
}
void displayStudents()
{
    int i;

    if (count == 0)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nRoll No : %d", s[i].roll);
        printf("\nName    : %s", s[i].name);
        printf("\nMarks   : %.2f\n", s[i].marks);
    }
}
void searchStudent()
{
    int roll, i;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll No : %d\n", s[i].roll);
            printf("Name    : %s\n", s[i].name);
            printf("Marks   : %.2f\n", s[i].marks);
            return;
        }
    }

    printf("Student Not Found!\n");
}
void deleteStudent()
{
    int roll, i, j;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            for (j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            count--;
            printf("Record Deleted Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            printf("Thank You!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}