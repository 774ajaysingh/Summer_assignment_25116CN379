/*Write a program to Convert binary to decimal.*/
int main() {
    int bin, dec = 0, remainder, i = 0;

    printf("Enter a binary number: ");
    scanf("%d", &bin);

    while (bin != 0) {
        remainder = bin % 10;
        dec += remainder * pow(2, i);
        bin /= 10;
        i++;
    }

    printf("Decimal equivalent: %d", dec);
    return 0;
}