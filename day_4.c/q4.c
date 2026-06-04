/*Write a program to Print Armstrong numbers 
in a range. */
#include <stdio.h>
#include <math.h>

int main() {
    int s, e, num, temp, digit, digits;
    int sum;

    printf("Enter starting number: ");
    scanf("%d", &s);

    printf("Enter ending number: ");
    scanf("%d", &e);

    printf("Armstrong numbers between %d and %d are:\n", s, e);

    for (num = s; num <= e; num++) {
        temp = num;
        digits = 0;
        sum = 0;
        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = num;
        while (temp != 0) {
            digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }

        if (sum == num)
            printf("%d ", num);
    }

    return 0;
}