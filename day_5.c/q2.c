/*Write a program to Check strong number. */
#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, temp, rem, add = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while (temp > 0) {
        rem = temp % 10;
        add += factorial(rem);
        temp /= 10;
    }

    if (add == n)
        printf("%d is a Strong Number.", n);
    else
        printf("%d is not a Strong Number.", n);

    return 0;
}