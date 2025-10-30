#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct {
    int stk[MAX];
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
void push(Stack *s,int data) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->stk[++(s->top)] = data;
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1; 
    }
    return s->stk[(s->top)--];
}
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;  
    }
    return s->stk[s->top];
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    

    Stack mstk;
    initializeStack(&mstk);

    
    // reading 5 numbers from user and pushing into stack
    int arr[5];
    for (int i = 0; i < 5; i++) {
	scanf("%i", &arr[i]);
    }
    
    start = clock();
    //sorting
    for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4-i; j++) {
	    if(arr[j] < arr[j+1]) {
		int temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
	    }
	}
    }

    // adding into stack
    for (int i = 0; i < 5; i++) {
	push(&mstk, arr[i]);
    }
    
    //printing that stack
    for(int i = 0; i < 5; i++) {
	printf("%i, ", pop(&mstk));
    }
   


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taked : %f second", cpu_time_used);
    return 0;
}

