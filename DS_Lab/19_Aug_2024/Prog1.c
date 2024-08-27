// Q. Write a program to create a single linked list of n nodes and perform the following menu-based operations on it using function:
// i. Insert a node at specific position
// ii. Insert a node at the beginning
// iii. Deletion of an element from specific position
// iv. Count nodes
// v. Traverse the linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct Node *next;
};

struct Node *createNode(int element);

// List of the functions required for this program
void insertNodeAtSpecificPosition(struct Node **head, int element, int position);
void insertNodeAtBeginning(struct Node **head, int element);
void deleteAtSpecificPosition(struct Node **head, int position);
int countNodes(struct Node *head);
void traverseLinkedList(struct Node *head);

int main() {
    struct Node *head = NULL;
    int element, choice, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at specific position\n");
        printf("2. Insert a node at the beginning\n");
        printf("3. Delete an element from specific position\n");
        printf("4. Count the number of nodes\n");
        printf("5. Traverse the linked list\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position where the element is to be inserted: ");
            scanf("%d", &position);
            insertNodeAtSpecificPosition(&head, element, position);
            break;

        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insertNodeAtBeginning(&head, element, position);
            break;

        case 3:
            printf("Enter the element to be deleted: ");
            scanf("%d", &element);
            printf("Enter the position from where the element is to be deleted: ");
            scanf("%d", &position);
            deleteAtSpecificPosition(&head, element, position);
            break;

        case 4:
            printf("The total number of nodes present are: %d\n", countNodes(head));
            break;

        case 5:
            traverseList(head);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to create a new node
struct Node *createNode(int element) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->element = element;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position
void insertNodeAtSpecificPosition (struct Node **head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node at the beginning
void insertNodeAtBeginning(struct Node **head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete an element from a specific position
void deleteAtSpecificPosition(struct Node **head, int data, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Function to traverse the linked list
void traverseLinkedList(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}