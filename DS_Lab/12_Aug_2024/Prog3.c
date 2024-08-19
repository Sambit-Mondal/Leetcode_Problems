// Q. Given two polynomials represented by two arrays, write a function that adds given two polynomials.

#include <stdio.h>

void addPolynomials(int A[], int B[], int m, int n, int sum[]) {
    int i;

    for (i = 0; i < (m > n ? m : n); i++) {
        sum[i] = 0;
    }

    for (i = 0; i < m; i++) {
        sum[i] += A[i];
    }
    for (i = 0; i < n; i++) {
        sum[i] += B[i];
    }
}

int main() {
    int m, n;

    printf("Enter the degree of the first polynomial (highest power of x + 1): ");
    scanf("%d", &m);
    int A[m];

    // Input coefficients of the first polynomial
    printf("Enter the coefficients of the first polynomial:\n");
    for (int i = 0; i < m; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &A[i]);
    }

    // Input size of the second polynomial
    printf("Enter the degree of the second polynomial (highest power of x + 1): ");
    scanf("%d", &n);
    int B[n];

    // Input coefficients of the second polynomial
    printf("Enter the coefficients of the second polynomial:\n");
    for (int i = 0; i < n; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &B[i]);
    }

    int sum[m > n ? m : n];

    addPolynomials(A, B, m, n, sum);

    printf("Sum of the two polynomials is:\n");
    for (int i = 0; i < (m > n ? m : n); i++) {
        printf("%d", sum[i]);
        if (i != 0) {
            printf("x^%d", i);
        }
        if (i != (m > n ? m : n) - 1) {
            printf(" + ");
        }
    }
    printf("\n");

    return 0;
}