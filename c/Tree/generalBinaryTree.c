#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node* NODE;

// creating a new node
NODE createNode(int val) {
    NODE nNode = (NODE)malloc(sizeof(struct Node));
    nNode->data = val;
    nNode->left = nNode->right = NULL;
    return nNode;
}

// insertion in a binary tree
void insertbt(NODE root, int key) {
    if(root == NULL) return;
    if(root->left == NULL) {
        root->left = createNode(key);
        return;
    } else if (root->right == NULL) {
        root->right = createNode(key);
        return;
    }
    if(rand() % 2)
        insertbt(root->left, key);
    else
        insertbt(root->right, key);
}



// insertion in a binary search tree
void insertbst(NODE root, int key) {
    if(root == NULL) return;
    if(root->left == NULL && root->data > key) {
        root->left = createNode(key);
        return;
    } else if (root->right == NULL && root->data < key) {
        root->right = createNode(key);
        return;
    }
    if(root->data > key)
        insertbst(root->left, key);
    else
        insertbst(root->right, key);
}

// conversion to bst
void convert(NODE root, NODE bstroot){
    if(root == NULL) return;
    convert(root->left, bstroot);
    if(root->data != bstroot->data)
        insertbst(bstroot, root->data);
    convert(root->right, bstroot);
}

// display of tree with in-order traversal
void inOrder(NODE root) {
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}


int main () {
    // creating tree
    NODE rootBT = createNode(8);
    insertbt(rootBT, 3);
    insertbt(rootBT, 5);
    insertbt(rootBT, 10);
    insertbt(rootBT, 2);
    insertbt(rootBT, 4);
    insertbt(rootBT, 6);

    // bst conversion
    NODE rootBST = createNode(8);
    convert(rootBT, rootBST);
    
    printf("Binary Tree : ");
    inOrder(rootBT);
    printf("\n");
    printf("Binary Search Tree : ");
    inOrder(rootBST);
    return 0;
}