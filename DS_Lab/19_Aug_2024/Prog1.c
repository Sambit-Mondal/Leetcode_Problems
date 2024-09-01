// Q. Write a program to create a single linked list of n nodes and perform the following menu-based operations on it using function:
// i. Insert a node at specific position
// ii. Insert a node at the beginning
// iii. Deletion of an element from specific position
// iv. Count nodes
// v. Traverse the linked list

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node **head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from a specific position
void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to count the number of nodes
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to traverse the linked list and print the elements
void traverseList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at specific position\n");
        printf("2. Insert a node at the beginning\n");
        printf("3. Delete a node from specific position\n");
        printf("4. Count nodes\n");
        printf("5. Traverse the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 4:
            printf("Number of nodes: %d\n", countNodes(head));
            break;
        case 5:
            printf("Linked list: ");
            traverseList(head);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
