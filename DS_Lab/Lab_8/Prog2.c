// In addition to the Prog1, perform the following menu driven operations on BST.
// i. insert an element to the BST
// ii. display the largest element
// iii. display the smallest element
// iv. height of a node
// v. count number of leaf nodes


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert an element into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the largest element in the BST
int findLargest(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

// Function to find the smallest element in the BST
int findSmallest(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to find the height of a node
int height(struct Node* node) {
    if (node == NULL) {
        return -1;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Function to count the number of leaf nodes
int countLeafNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;
    } else {
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }
}

// Function to display the menu and perform operations
void menu() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element to the BST\n");
        printf("2. Display the largest element\n");
        printf("3. Display the smallest element\n");
        printf("4. Height of the BST\n");
        printf("5. Count number of leaf nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                if (root != NULL) {
                    printf("Largest element: %d\n", findLargest(root));
                } else {
                    printf("BST is empty.\n");
                }
                break;
            case 3:
                if (root != NULL) {
                    printf("Smallest element: %d\n", findSmallest(root));
                } else {
                    printf("BST is empty.\n");
                }
                break;
            case 4:
                printf("Height of the BST: %d\n", height(root));
                break;
            case 5:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}