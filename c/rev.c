#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};
typedef struct Node* NODE;

NODE create(int x){
    NODE n = (NODE)malloc(sizeof(struct Node));
    n->val = x;
    n->next = NULL;
    return n;
}

void insert(NODE *head, int val){
    NODE newNode = create(val);
    newNode->next = *head;
    *head = newNode;
}

NODE reverse(NODE head){
    NODE pre = NULL, curr = head;
    while(curr){
        NODE n = curr->next;
        curr->next = pre;
        pre = curr;
        curr = n;
    }
    return pre;
}




void display(NODE head){
    NODE temp = head;
    while(temp){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main () {
    NODE h = create(1);
    insert(&h, 2);
    insert(&h, 3);
    display(h);

    NODE revhead = reverse(h);

    display(revhead);
    return 0;
}