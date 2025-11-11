
#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};
typedef struct Node* NODE;

// Creating a new node
NODE create(int val){
  NODE nNode = (NODE)malloc(sizeof(struct Node));
  nNode->data = val;
  nNode->left = nNode->right = NULL;
  return nNode;
}

// Inserting a new element
void insert(NODE root, int key){
  NODE curr = create(key);
  if(root == NULL) return;
  if(root->left == NULL){
    root->left = curr;
  } else if(root->right == NULL){
    root->right = curr;
  } else {
    if(rand() % 2){
      insert(root->left, key);
    } else {
      insert(root->right, key);
    }
  }
}

// Finding the deepest node
NODE deepestNode(NODE root){
  if(root == NULL) return NULL;
  NODE queue[1000];
  int f = 0, r = 0;
  queue[r++] = root;
  NODE temp;
  while(f < r){
    temp = queue[f++];
    if(temp->left) queue[r++] = temp->left;
    if(temp->right) queue[r++] = temp->right;
  }
  return temp;
}

// Deleting the deepest node
void deletedeepest(NODE root, NODE delNode){
  if(root == NULL) return;
  if(root->right == delNode){
    free(root->right);
    root->right = NULL;
    return;
  }
  if(root->left == delNode){
    free(root->left);
    root->left = NULL;
    return;
  }
  if(root->right) deletedeepest(root->right, delNode);
  if(root->left) deletedeepest(root->left, delNode);
}

// Deleting a node
NODE deleteNode(NODE root, int key){
  if(root == NULL) return NULL;
  if(root->data == key){
    NODE dep = deepestNode(root);
    root->data = dep->data;
    deletedeepest(root, dep);
    return root;
  }
  root->left = deleteNode(root->left, key);
  root->right = deleteNode(root->right, key);
  return root;
}

// Number of nodes
int noOfNodes(NODE root){
  if(root==NULL) return 0;
  return noOfNodes(root->left) + noOfNodes(root->right) + 1;
}

// Height of tree
int height(NODE root){
  if(root==NULL) return 0;
  int l = height(root->left);
  int r = height(root->right);
  return (l > r ? l : r) + 1;
}

// Diameter of tree
int diameter(NODE root){
  if(root==NULL) return 0;
  int lht = height(root->left);
  int rht = height(root->right);
  int rootd = lht + rht + 1;
  int ldia = diameter(root->left);
  int rdia = diameter(root->right);
  int max = ldia > rdia ? ldia : rdia;
  return max > rootd ? max : rootd;
}

// Level order traversal
void levelOrder(NODE root){
  if(root==NULL) return;
  NODE queue[1000];
  int f = 0, r = 0;
  queue[r++] = root;
  while(f < r){
    NODE temp = queue[f++];
    printf("%d ", temp->data);
    if(temp->left) queue[r++] = temp->left;
    if(temp->right) queue[r++] = temp->right;
  }
}

// Inorder traversal
void inOrder(NODE root){
  if(root==NULL) return;
  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
}

int main() {
  NODE R = create(1);
  insert(R, 2);
  insert(R, 3);
  insert(R, 4);
  insert(R, 5);
  
  printf("InOrder Traversal Before Deletion: ");
  inOrder(R);
  printf("\n");
  
  printf("Level Order Traversal: ");
  levelOrder(R);
  printf("\n");
  
  printf("Height: %d\n", height(R));
  printf("Diameter: %d\n", diameter(R));
  printf("Number of Nodes: %d\n", noOfNodes(R));
  
  R = deleteNode(R, 2);
  
  printf("InOrder Traversal After Deletion: ");
  inOrder(R);
  printf("\n");
  
  return 0;
}
