#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Deque;

void initializeDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
    } else {
        if (dq->front == -1) {
            dq->front = 0;
            dq->rear = 0;
        } else if (dq->front == 0) {
            dq->front = SIZE - 1;
        } else {
            dq->front = dq->front - 1;
        }
        dq->items[dq->front] = value;
        printf("Inserted %d at front\n", value);
    }
}

void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
    } else {
        if (dq->front == -1) {
            dq->front = 0;
            dq->rear = 0;
        } else if (dq->rear == SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear = dq->rear + 1;
        }
        dq->items[dq->rear] = value;
        printf("Inserted %d at rear\n", value);
    }
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deleted %d from front\n", dq->items[dq->front]);
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        } else if (dq->front == SIZE - 1) {
            dq->front = 0;
        } else {
            dq->front = dq->front + 1;
        }
    }
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deleted %d from rear\n", dq->items[dq->rear]);
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        } else if (dq->rear == 0) {
            dq->rear = SIZE - 1;
        } else {
            dq->rear = dq->rear - 1;
        }
    }
}

void displayDeque(Deque *dq) {
    int i;
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
    } else {
        printf("Front -> %d\n", dq->front);
        printf("Items -> ");
        for (i = dq->front; i != dq->rear; i = (i + 1) % SIZE) {
            printf("%d ", dq->items[i]);
        }
        printf("%d ", dq->items[i]);
        printf("\nRear -> %d\n", dq->rear);
    }
}

void menu() {
    printf("1. Insert Front\n");
    printf("2. Insert Rear\n");
    printf("3. Delete Front\n");
    printf("4. Delete Rear\n");
    printf("5. Display Deque\n");
    printf("6. Exit\n");
}

int main() {
    Deque dq;
    initializeDeque(&dq);

    int choice, value;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                displayDeque(&dq);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
