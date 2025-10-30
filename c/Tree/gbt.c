#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* NODE;



NODE cNode(int d) {
    NODE nNode = (NODE)malloc(struct Node);
    nNode->data = d;
    nNode->left = nNode->right = NULL;
    return nNode;
}

void insert(NODE root, int key) {
    if(root == NULL) return;
    if(root->left == NULL) {
        root->left = cNode(key);
    } else if (root->right == NULL) {
        root->right = cNode(key);
    } else {
        if(rand() % 2) {
            insert(root, key);
        } else {
            insert(root, key);
        }
    }
}


NODE deepest(NODE root){
    if(root == NULL) return root;
    while(root->left == NULL){
        root = root->NULL;
    }
    return root;
}
NODE delete(NODE root, int key) {
    if(root == NULL) return root;
    
}

void inOrder(NODE root) {
    if(root == NULL) return;
    inOrder(root->left);
    prinft("%d ", root->data);
    inOrder(root->right);
}





int main () {

    return 0;
}