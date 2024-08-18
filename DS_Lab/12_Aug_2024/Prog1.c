// Q. Write a program to represent a given sparse matrix in 3-tuple format using 2-D array.

#include <stdio.h>

int main() {
    int row, col, i, j, k = 0, nonZeroCount = 0;
    
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int matrix[row][col];

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    int tuple[nonZeroCount + 1][3];

    tuple[0][0] = row;
    tuple[0][1] = col;
    tuple[0][2] = nonZeroCount;

    k = 1;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("\n3-Tuple representation:\n");
    printf("Row  Column  Value\n");
    for(i = 0; i <= nonZeroCount; i++) {
        printf("%d     %d     %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }

    return 0;
}