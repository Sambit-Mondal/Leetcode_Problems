// Q. Write a menu driven program to create a stack using array and perform the following operation using function:
// 1. Push
// 2. Pop
// 3. Check stack is empty or not
// 4. Check stack is full or not
// 5. Display stack elements


#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int MAX;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack is full!\n");
    } else {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top--]);
    }
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    printf("Enter the size of the stack: ");
    scanf("%d", &MAX);

    stack = (int *)malloc(MAX * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if stack is empty\n");
        printf("4. Check if stack is full\n");
        printf("5. Display stack elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 5:
                display();
                break;
            case 6:
                free(stack);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}