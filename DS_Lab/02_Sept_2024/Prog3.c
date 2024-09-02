// Q. Write a program to represent the given sparse matrix using header single linked list and display it.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Node* head) {
    struct Node* temp = head;
    printf("Row\tColumn\tValue\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    struct Node* head = NULL;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                insertNode(&head, i, j, matrix[i][j]);
            }
        }
    }

    printf("Sparse Matrix:\n");
    displaySparseMatrix(head);

    return 0;
}