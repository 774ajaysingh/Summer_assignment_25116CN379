/*Write a program to Create mini employee 
management system. */

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define DEPT_LENGTH 30

struct Employee {
    int id;
    char name[NAME_LENGTH];
    char department[DEPT_LENGTH];
    float salary;
};

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int findEmployeeById(const struct Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void displayEmployee(const struct Employee *employee) {
    printf("ID: %d\n", employee->id);
    printf("Name: %s\n", employee->name);
    printf("Department: %s\n", employee->department);
    printf("Salary: %.2f\n", employee->salary);
}

void displayAllEmployees(const struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employee records available.\n");
        return;
    }
    printf("\nEmployee List:\n");
    for (int i = 0; i < count; i++) {
        printf("---------------------------\n");
        displayEmployee(&employees[i]);
    }
    printf("---------------------------\n");
}

int main(void) {
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do {
        printf("\nMini Employee Management System\n");
        printf("1. Add employee\n");
        printf("2. Display all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Update employee salary\n");
        printf("5. Delete employee\n");
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
                if (employeeCount >= MAX_EMPLOYEES) {
                    printf("Employee list is full.\n");
                    break;
                }
                printf("Enter employee ID: ");
                scanf("%d", &employees[employeeCount].id);
                while (getchar() != '\n');
                if (findEmployeeById(employees, employeeCount, employees[employeeCount].id) != -1) {
                    printf("Employee with this ID already exists.\n");
                    break;
                }
                printf("Enter employee name: ");
                readLine(employees[employeeCount].name, NAME_LENGTH);
                printf("Enter department: ");
                readLine(employees[employeeCount].department, DEPT_LENGTH);
                printf("Enter salary: ");
                scanf("%f", &employees[employeeCount].salary);
                while (getchar() != '\n');
                employeeCount++;
                printf("Employee added successfully.\n");
                break;
            case 2:
                displayAllEmployees(employees, employeeCount);
                break;
            case 3:
                if (employeeCount == 0) {
                    printf("No employee records available.\n");
                    break;
                }
                printf("Enter employee ID to search: ");
                {
                    int searchId;
                    scanf("%d", &searchId);
                    while (getchar() != '\n');
                    int index = findEmployeeById(employees, employeeCount, searchId);
                    if (index == -1) {
                        printf("Employee not found.\n");
                    } else {
                        displayEmployee(&employees[index]);
                    }
                }
                break;
            case 4:
                if (employeeCount == 0) {
                    printf("No employee records available.\n");
                    break;
                }
                printf("Enter employee ID to update salary: ");
                {
                    int updateId;
                    scanf("%d", &updateId);
                    while (getchar() != '\n');
                    int index = findEmployeeById(employees, employeeCount, updateId);
                    if (index == -1) {
                        printf("Employee not found.\n");
                    } else {
                        printf("Enter new salary: ");
                        scanf("%f", &employees[index].salary);
                        while (getchar() != '\n');
                        printf("Salary updated successfully.\n");
                    }
                }
                break;
            case 5:
                if (employeeCount == 0) {
                    printf("No employee records available.\n");
                    break;
                }
                printf("Enter employee ID to delete: ");
                {
                    int deleteId;
                    scanf("%d", &deleteId);
                    while (getchar() != '\n');
                    int index = findEmployeeById(employees, employeeCount, deleteId);
                    if (index == -1) {
                        printf("Employee not found.\n");
                    } else {
                        for (int i = index; i < employeeCount - 1; i++) {
                            employees[i] = employees[i + 1];
                        }
                        employeeCount--;
                        printf("Employee deleted successfully.\n");
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
