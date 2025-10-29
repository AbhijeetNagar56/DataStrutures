#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}; 

typedef struct Node* NODE; 

NODE createNode(int key) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(NODE root, int key) {
    if (root == NULL) return;

    if (root->left == NULL) {
        root->left = createNode(key);
        return;
    } else if (root->right == NULL) {
        root->right = createNode(key);
        return;
    }

    if (rand() % 2)
        insert(root->left, key);
    else
        insert(root->right, key);
}

int search(NODE root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    return search(root->left, key) || search(root->right, key);
}

NODE deleteDeepest(NODE root, NODE delNode) {
    if (root == NULL) return NULL;
    if (root == delNode) {
        free(root);
        return NULL;
    }
    if (root->right) {
        if (root->right == delNode) {
            free(root->right);
            root->right = NULL;
            return root;
        } else {
            root->right = deleteDeepest(root->right, delNode);
        }
    }
    if (root->left) {
        if (root->left == delNode) {
            free(root->left);
            root->left = NULL;
            return root;
        } else {
            root->left = deleteDeepest(root->left, delNode);
        }
    }
    return root;
}

NODE deleteNode(NODE root, int key) {
    if (root == NULL) return NULL;
    
    NODE target = NULL, last = NULL, parent = NULL;
    NODE queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        NODE temp = queue[front++];
        if (temp->data == key) target = temp;
        if (temp->left) {
            parent = temp;
            last = temp->left;
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            parent = temp;
            last = temp->right;
            queue[rear++] = temp->right;
        }
    }

    if (target) {
        target->data = last->data;
        root = deleteDeepest(root, last);
    }
    return root;
}

void inorder(NODE root) {
    if (root == NULL) return;
    inorder(root->left); 
    printf("%d ", root->data);
    inorder(root->right); 
}

int main() {
    NODE root = createNode(1);

    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("%s\n", search(root, 5) ? "5 in tree" : "5 not in tree");
    printf("%s\n", search(root, 10) ? "10 in tree" : "10 not in tree");

    root = deleteNode(root, 3);
    printf("Inorder Traversal after deleting 3 : ");
    inorder(root);
    printf("\n");

    return 0;
}
