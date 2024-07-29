// Q: Write a menu driven program to create a structure to represent Complex number and perform the following operations using fucntion:
// i. addition of two Complex number (call by value)
// ii. multiplication of two Complex number (call by address)

#include <stdio.h>

typedef struct {
    float real;
    float imag;
} complexNum;


complexNum addcomplexNum(complexNum c1, complexNum c2) {
    complexNum result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}


void multiplycomplexNum(complexNum *c1, complexNum *c2, complexNum *result) {
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}


int main() {
    complexNum c1, c2, result;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add two Complex numbers\n");
        printf("2. Multiply two Complex numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first Complex number (real and imaginary): ");
                scanf("%f %f", &c1.real, &c1.imag);
                printf("Enter the second Complex number (real and imaginary): ");
                scanf("%f %f", &c2.real, &c2.imag);

                result = addcomplexNum(c1, c2);
                printf("Result of addition: %.2f + %.2fi\n", result.real, result.imag);
                break;

            case 2:
                printf("Enter the first Complex number (real and imaginary): ");
                scanf("%f %f", &c1.real, &c1.imag);
                printf("Enter the second Complex number (real and imaginary): ");
                scanf("%f %f", &c2.real, &c2.imag);

                multiplycomplexNum(&c1, &c2, &result);
                printf("Result of multiplication: %.2f + %.2fi\n", result.real, result.imag);
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}