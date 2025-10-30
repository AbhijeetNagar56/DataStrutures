#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;
void initializeStack(Stack *s) {
    s->top = -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++(s->top)] = item;
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;  // Return an error value
    }
    return s->items[(s->top)--];
}
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;  // Return an error value
    }
    return s->items[s->top];
}
int main() {
    Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element is %d\n", peek(&myStack));
    printf("Popped element is %d\n", pop(&myStack));
    printf("Top element after pop is %d\n", peek(&myStack));

    return 0;
}

