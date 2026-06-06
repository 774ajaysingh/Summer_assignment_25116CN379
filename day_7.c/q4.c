/*Write a program to Recursive reverse number.*/
int reverse = 0;

int reverseNumber(int n) {
    if (n == 0)
        return 0;

    reverse = reverse * 10 + (n % 10);
    reverseNumber(n / 10);

    return reverse;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Reversed number = %d\n", reverseNumber(n));

    return 0;
}