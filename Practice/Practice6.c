#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrix;

void transposeSparseMatrix(SparseMatrix original[], SparseMatrix transposed[]) {
    int i, j, k = 1;
    int numTerms = original[0].value;
    transposed[0].row = original[0].col;
    transposed[0].col = original[0].row;
    transposed[0].value = numTerms;

    if (numTerms > 0) {
        for (i = 0; i < original[0].col; i++) {
            for (j = 1; j <= numTerms; j++) {
                if (original[j].col == i) {
                    transposed[k].row = original[j].col;
                    transposed[k].col = original[j].row;
                    transposed[k].value = original[j].value;
                    k++;
                }
            }
        }
    }
}

void printSparseMatrix(SparseMatrix matrix[]) {
    int numTerms = matrix[0].value;
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= numTerms; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    SparseMatrix original[MAX];
    SparseMatrix transposed[MAX];
    int numTerms, rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numTerms);

    original[0].row = rows;
    original[0].col = cols;
    original[0].value = numTerms;

    for (int i = 1; i <= numTerms; i++) {
        printf("Enter row, column and value of element %d: ", i);
        scanf("%d %d %d", &original[i].row, &original[i].col, &original[i].value);
    }

    transposeSparseMatrix(original, transposed);

    printf("Original Sparse Matrix:\n");
    printSparseMatrix(original);

    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(transposed);

    return 0;
}