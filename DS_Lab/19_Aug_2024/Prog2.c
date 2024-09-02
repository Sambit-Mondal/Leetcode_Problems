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

// Function to create a linked list with 'n' nodes
struct Node* createLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    if (n <= 0) {
        printf("Number of nodes must be greater than 0\n");
        return NULL;
    }

    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
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
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    *head = prev;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, choice, key, position;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    head = createLinkedList(n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Search for an element in the list\n");
        printf("2. Reverse the list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                position = searchElement(head, key);
                if (position != -1) {
                    printf("Element %d found at position %d\n", key, position);
                } else {
                    printf("Element %d not found in the list\n", key);
                }
                break;
            case 2:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}