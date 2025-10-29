#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} CircularQueue;

void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    if ((q->front == 0 && q->rear == SIZE - 1) || (q->front == q->rear + 1)) {
        return 1;
    }
    return 0;
}

int isEmpty(CircularQueue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue(CircularQueue *q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("Deleted %d\n", value);
        return value;
    }
}

void displayQueue(CircularQueue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front -> %d\n", q->front);
        printf("Items -> ");
        for (i = q->front; i != q->rear; i = (i + 1) % SIZE) {
            printf("%d ", q->items[i]);
        }
        printf("%d ", q->items[i]);
        printf("\nRear -> %d\n", q->rear);
    }
}

void menu() {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
}

int main() {
    CircularQueue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
