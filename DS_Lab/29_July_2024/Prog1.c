// Q: Write a program to read two numbers and compare the numbers using function call by address.

#include <stdio.h>

void compareNumbers(int *, int *);

int main() {
    int number1, number2;

    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);

    compareNumbers(&number1, &number2);

    return 0;
}


void compareNumbers(int *num1, int *num2) {
    if (*num1 > *num2) {
        printf("%d is greater than %d\n", *num1, *num2);
    } else if (*num1 < *num2) {
        printf("%d is greater than %d\n", *num2, *num1);
    } else {
        printf("%d is equal to %d\n", *num1, *num2);
    }
}