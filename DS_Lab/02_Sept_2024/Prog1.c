// Q. Write a program to create a double linked list and perform the following menu-based operations on it:
// i. insert an element at specific position
// ii. delete an element from specific position
// iii. traverse the list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert an element at specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    if (position == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (current->next != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (count == position - 1) {
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    } else {
        printf("Invalid position!");
    }
}

// Function to delete an element from specific position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!");
        return;
    }
    struct Node* current = *head;
    if (position == 1) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    if (current != NULL) {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    } else {
        printf("Invalid position!");
    }
}

// Function to traverse the list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!");
        return;
    }
    struct Node* current = head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, choice, data, position;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtPosition(&head, data, i + 1);
    }
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element at specific position\n");
        printf("2. Delete an element from specific position\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter the position of the element to be deleted: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}