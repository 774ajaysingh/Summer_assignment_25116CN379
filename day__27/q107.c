/*Write a program to Create salary management 
system. */

#include <stdio.h>
int main() {        
    
    float basic_salary, hra, da, gross_salary;

    printf("Enter the basic salary: ");
    scanf("%f", &basic_salary);
    hra = 0.2 * basic_salary;
    da = 0.1 * basic_salary;
    gross_salary = basic_salary + hra + da;

    printf("Basic Salary: %.2f\n", basic_salary);
    printf("HRA (20%%): %.2f\n", hra);
    printf("DA (10%%): %.2f\n", da);
    printf("Gross Salary: %.2f\n", gross_salary);

    return 0;
}