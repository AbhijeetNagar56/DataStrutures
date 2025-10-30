#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int que[MAX];
    int front, rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q) {
    return q->front == -1;
}
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
	    q->front = 0;
    }
    q->que[++(q->rear)] = data;
}

int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->que[q->front];
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->que[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1; 
    } else {
        q->front++;
    }
    return item;
}
int noOfElement(Queue *q) {
    if (isEmpty(q)){
        return 0;
    }
    return q->rear - q->front + 1;
}




int main () {
    Queue newq;
    initializeQueue(&newq);
    
    }
}