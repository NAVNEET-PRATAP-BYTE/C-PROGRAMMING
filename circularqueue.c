#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;
int queueSize;

void enqueue(int value) {
    if ((rear + 1) % queueSize == front) {
        printf("Queue Overflow!\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % queueSize;
        queue[rear] = value;
        printf("Enqueued %d to the queue\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
    } else {
        printf("Dequeued %d from the queue\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % queueSize;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % queueSize;
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
