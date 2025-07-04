#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;
int queueSize;

void enqueue(int value) {
    if (rear >= queueSize - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Enqueued %d to the queue\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        front = rear = -1;
    } else {
        printf("Dequeued %d from the queue\n", queue[front++]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    printf("Enter the queue size (max %d): ", MAX_SIZE);
    scanf("%d", &queueSize);
    
    if (queueSize > MAX_SIZE || queueSize <= 0) {
        printf("Invalid queue size!\n");
        return 1;
    }
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
