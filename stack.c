#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;
int stackSize;

void push(int value) {
    if (top >= stackSize - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;
        printf("Pushed %d to the stack\n", value);
    }
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
    } else {
        printf("Popped %d from the stack\n", stack[top--]);
    }
}

void peek() {
    if (top < 0) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void display() {
    if (top < 0) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    printf("Enter the stack size (max %d): ", MAX_SIZE);
    scanf("%d", &stackSize);
    
    if (stackSize > MAX_SIZE || stackSize <= 0) {
        printf("Invalid stack size!\n");
        return 1;
    }
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
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
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
