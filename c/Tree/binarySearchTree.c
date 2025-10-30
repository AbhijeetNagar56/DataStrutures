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



// display of tree with in-order traversal
void inOrder(NODE root) {
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// height calculation
int height(NODE root){
    if(root == NULL) return 0;
    int lht = height(root->left);
    int rht = height(root->right);
    return ((lht > rht) ? lht : rht) + 1;
}

// Checking wheather the tree is avl or not

int isAVL(NODE root) {
    if (root == NULL) return 1;

    int leftAVL = isAVL(root->left);
    int rightAVL = isAVL(root->right);

    int balanceFactor = height(root->left) - height(root->right);

    if (leftAVL && rightAVL && (balanceFactor >= -1 && balanceFactor <= 1)) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
    // creating tree
    NODE rootBST = createNode(12);
    insertbst(rootBST, 8);
    insertbst(rootBST, 18);
    insertbst(rootBST, 5);
    insertbst(rootBST, 11);
    insertbst(rootBST, 17);
    insertbst(rootBST, 4);

    printf("height of tree is : %d ", height(rootBST));
    printf("\nchecking if avl or not : ");
    printf("%s", (isAVL(rootBST)) ? "AVL tree" : "Not an AVL");
    return 0;
}