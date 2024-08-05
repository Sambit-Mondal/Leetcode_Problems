// Q. Write a Program to create a 1-D array of n elements and perform the following menu based operations using function:
// a. insert a given element from a specific position of the array.
// b. delete an element from a specific position of the array.
// c. linear search to search for an element.
// d. traversal of the array.

#include <stdio.h>

void insert(int arr[], int *n, int element, int position) {
    if (position > *n + 1 || position < 1) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
}

void delete(int arr[], int *n, int position) {
    if (position > *n || position < 1) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int linearSearch(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void traverse(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n, choice, element, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n***Menu:***\n");
        printf("1. Insert an element at a specific position\n");
        printf("2. Delete an element from a specific position\n");
        printf("3. Linear search for an element\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert the element: ");
                scanf("%d", &position);
                insert(arr, &n, element, position);
                break;

            case 2:
                printf("\nEnter the position to delete the element: ");
                scanf("%d", &position);
                delete(arr, &n, position);
                break;

            case 3:
                printf("\nEnter the element to search for: ");
                scanf("%d", &element);
                position = linearSearch(arr, n, element);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found in the array\n");
                }
                break;

            case 4:
                traverse(arr, n);
                break;

            case 5:
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}