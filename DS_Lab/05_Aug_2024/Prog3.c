// Q. Write a program to perform the following operations on a given square matrix using functions:
// i. Find the number of non-zero elements.
// ii. Display upper triangular matrix.
// iii. Display the elements of just above and below the main diagonal.

#include <stdio.h>

#define SIZE 3

int countNonZeroElements(int matrix[SIZE][SIZE], int size);
void displayUpperTriangularMatrix(int matrix[SIZE][SIZE], int size);
void displayAboveBelowDiagonalElements(int matrix[SIZE][SIZE], int size);

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 2, 3},
        {0, 5, 6},
        {0, 0, 9}
    };
    
    int nonZeroCount = countNonZeroElements(matrix, SIZE);
    printf("Number of non-zero elements: %d\n", nonZeroCount);

    printf("Upper triangular matrix:\n");
    displayUpperTriangularMatrix(matrix, SIZE);

    printf("Elements just above and below the main diagonal:\n");
    displayAboveBelowDiagonalElements(matrix, SIZE);

    return 0;
}

int countNonZeroElements(int matrix[SIZE][SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

void displayUpperTriangularMatrix(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j >= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void displayAboveBelowDiagonalElements(int matrix[SIZE][SIZE], int size) {
    printf("Above diagonal elements: ");
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", matrix[i][i + 1]);
    }
    printf("\nBelow diagonal elements: ");
    for (int i = 1; i < size; i++) {
        printf("%d ", matrix[i][i - 1]);
    }
    printf("\n");
}