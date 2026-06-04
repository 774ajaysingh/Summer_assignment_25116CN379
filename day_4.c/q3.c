/*Write a program to Check Armstrong number.*/
#include <stdio.h>

int main() {
    int num, oNum, r;
    int result = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    oNum = num;

    while (num != 0) {
        r = num % 10;
        result += r * r * r;
        num /= 10;
    }

    if (result == oNum)
        printf("%d is an Armstrong number.", oNum);
    else
        printf("%d is not an Armstrong number.", oNum);

    return 0;
}