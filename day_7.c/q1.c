/*Write a program to Recursive factorial.*/
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;          // Base case
    else
        return n * factorial(n - 1); // Recursive call
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorial of %d = %d\n", n, factorial(n));

    return 0;
}