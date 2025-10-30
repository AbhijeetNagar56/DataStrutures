#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* NODE;

NODE createNode (int d) {
    NODE nNode = (NODE)malloc(sizeof(struct Node));
    nNode->data = d;
    nNode->left = nNode->right = NULL;
    return nNode;
}

//BST using this

void insert (NODE root, int value) {
    if (root == NULL) return;
    if (root->left == NULL && root->data>value) {
        root->left = createNode(value);
        return;
    } else if (root->right == NULL && root->data<value) {
        root->right = createNode(value);
        return;
    }
    if (root->data>value)
        insert(root->left, value);
    else 
        insert(root->right, value);
}

int search (NODE root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (root->data>key) {
        return search(root->left, key);
    } else {
        search(root->right, key);
    }
    
}

void display(NODE root) {
    if(root == NULL) return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

void levelOrderTraverse(NODE root) {
    if (root == NULL) return;


    NODE queue[1000]; 
    int front = 0, rear = 0;

    queue[rear++] = root; 

    while (front < rear) {
        NODE current = queue[front++];

        printf("%d ", current->data);

    
        if (current->left)
            queue[rear++] = current->left;

        
        if (current->right)
            queue[rear++] = current->right;
    }
}

int height (NODE root) {
    if (root == NULL) return 0;
    int lht = height(root->left);
    int rht = height(root->right);
    int max;
    if (lht>rht) {
        max = lht;
    } else {
        max = rht;
    }
    
    return max + 1;
}

int diameter (NODE root) {
    if (root == NULL) return 0;
    int lht = height(root->left);
    int rht = height(root->right);

    int rtdim = lht + rht + 1;

    int ldim = diameter(root->left);
    int rdim = diameter(root->right);

    return (rtdim > ldim) ? (rtdim > rdim ? rtdim : rdim)
                                         : (ldim > rdim ? ldim : rdim);
}

void allLeaf(NODE root) {
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        printf("%d ", root->data);
    }
    allLeaf(root->left);
    allLeaf(root->right);
}



// deletation

NODE minFromRST(NODE root){
    if (root == NULL) return root;
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}



NODE delete(NODE root, int key) {
    if(root == NULL) return root;

    if(key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        if(root->left == NULL) {
            NODE temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE temp = root->left;
            free(root);
            return temp;
        }
        
        NODE temp = minFromRST(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}


int main () {
    NODE root = createNode(5);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    
    // printf("%s\n", search(root, 7) ? "Yes" : "No");
    // levelOrderTraverse(root);
    // printf("%i ", height(root));

    // printf("%i ", diameter(root));
    // allLeaf(root);
  
    display(root);
    return 0;
}




