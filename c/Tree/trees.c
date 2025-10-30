#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE;

NODE create(int x){
    NODE n = (NODE)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void insert(NODE root, int val){
    if(root==NULL) return;
    if(root->left==NULL){
        root->left = create(val);
    } else if(root->right==NULL){
        root->right = create(val);
    } else {
        if(rand() % 2){
            insert(root->left, val);
        } else {
            insert(root->right, val);
        }
    }
}
int height(NODE r){
    if(r==NULL) return 0;
    int lht = height(r->left);
    int rht = height(r->right);
    return (lht > rht ? lht : rht)+1;
}

int diameter(NODE r){
    if(r==NULL) return 0;
    int rootDia = height(r->left) + height(r->right) + 1;
    int lDia = diameter(r->left);
    int rDia = diameter(r->right);
    int m = lDia > rDia ? lDia : rDia;
    return rootDia > m ? rootDia : m;
}
void level(NODE root){
    if(root==NULL) return;
    NODE que[100];
    int f = 0, r = 0;
    que[r++] = root;
    while(f != r){
        NODE curr = que[f++];
        printf("%d ", curr->data);
        if(curr->left){
            que[r++] = curr->left;
        } 
        if(curr->right){
            que[r++] = curr->right;
        }
    }
}
void delete(NODE root, int key){
    if(root==NULL) return;
    
}

void inOrder(NODE root){
    if(root==NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
int main () {
    NODE R = create(1);
    insert(R, 2);
    insert(R, 3);
    level(R);

    return 0;
}