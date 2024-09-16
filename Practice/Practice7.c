#include <stdio.h>
#include <stdlib.h>

void deleteElement(int **array, int rows, int *cols, int row, int col) {
    if (row >= rows || col >= cols[row]) {
        printf("Invalid position\n");
        return;
    }

    for (int i = col; i < cols[row] - 1; i++) {
        array[row][i] = array[row][i + 1];
    }

    cols[row]--;

    // Memory reallocation
    array[row] = realloc(array[row], cols[row] * sizeof(int));
    if (cols[row] > 0 && array[row] == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
}

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int *cols = malloc(rows * sizeof(int));
    int **array = malloc(rows * sizeof(int *));
    
    for (int i = 0; i < rows; i++) {
        printf("Enter the number of columns for row %d: ", i);
        scanf("%d", &cols[i]);
        array[i] = malloc(cols[i] * sizeof(int));
        for (int j = 0; j < cols[i]; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // Print the array before deletion
    printf("Array before deletion:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    int delRow, delCol;
    printf("Enter the row and column of the element to delete: ");
    scanf("%d %d", &delRow, &delCol);

    // Delete an element
    deleteElement(array, rows, cols, delRow, delCol);

    // Print the array after deletion
    printf("Array after deletion:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
    free(cols);

    return 0;
}