// Q. Perform following operations using function on the single linked list:
// i. Search an element in the list
// ii. Reverse the list

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to search for an element in the list
int searchElement(struct Node* head, int key) {
    int position = 1;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Element not found
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to traverse the linked list and print the elements
void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, key, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the end\n");
        printf("2. Search for an element in the list\n");
        printf("3. Reverse the list\n");
        printf("4. Traverse the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                position = searchElement(head, key);
                if (position != -1) {
                    printf("Element %d found at position %d\n", key, position);
                } else {
                    printf("Element %d not found in the list\n", key);
                }
                break;
            case 3:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 4:
                printf("Linked list: ");
                traverseList(head);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}