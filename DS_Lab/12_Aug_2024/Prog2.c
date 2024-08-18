// Q. Write a Program to add two sparse matrix (using array).

#include <stdio.h>

int createSparseMatrix(int rows, int cols, int matrix[rows][cols], int sparse[rows * cols + 1][3]) {
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;
    return k;
}

int addSparseMatrices(int sparse1[][3], int sparse2[][3], int result[][3]) {
    int i = 1, j = 1, k = 1;

    result[0][0] = sparse1[0][0];
    result[0][1] = sparse1[0][1];

    while (i <= sparse1[0][2] && j <= sparse2[0][2]) {
        if (sparse1[i][0] < sparse2[j][0] || (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1])) {
            result[k][0] = sparse1[i][0];
            result[k][1] = sparse1[i][1];
            result[k][2] = sparse1[i][2];
            i++;
        } else if (sparse1[i][0] > sparse2[j][0] || (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] > sparse2[j][1])) {
            result[k][0] = sparse2[j][0];
            result[k][1] = sparse2[j][1];
            result[k][2] = sparse2[j][2];
            j++;
        } else {
            result[k][0] = sparse1[i][0];
            result[k][1] = sparse1[i][1];
            result[k][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= sparse1[0][2]) {
        result[k][0] = sparse1[i][0];
        result[k][1] = sparse1[i][1];
        result[k][2] = sparse1[i][2];
        i++;
        k++;
    }
    while (j <= sparse2[0][2]) {
        result[k][0] = sparse2[j][0];
        result[k][1] = sparse2[j][1];
        result[k][2] = sparse2[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;
    return k;
}

void printSparseMatrix(int sparse[][3], int size) {
    printf("Row  Column  Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d     %d     %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols];

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int sparse1[rows * cols + 1][3], sparse2[rows * cols + 1][3];
    int size1 = createSparseMatrix(rows, cols, matrix1, sparse1);
    int size2 = createSparseMatrix(rows, cols, matrix2, sparse2);

    int result[rows * cols + 1][3];
    int resultSize = addSparseMatrices(sparse1, sparse2, result);

    printf("\nResultant Sparse Matrix (3-Tuple format):\n");
    printSparseMatrix(result, resultSize);

    return 0;
}