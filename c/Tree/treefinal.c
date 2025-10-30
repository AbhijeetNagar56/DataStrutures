
// #include <stdio.h>
// #include <stdlib.h>
// // Node structure
// struct Node {
//   int data;
//   struct Node* left;
//   struct Node* right;
// };
// typedef struct Node* NODE;

// // Creating a new node
// NODE create(int val){
//   NODE nNode = (NODE)malloc(sizeof(struct Node));
//   nNode->data = val;
//   nNode->left = nNode->right = NULL;
//   return nNode;
// }

// // Inserting a new element
// void insert(NODE root, int key){
//   NODE curr = create(key);
//   if(root == NULL) return;
//   if(root->left == NULL){
//     root->left = curr;
//   } else if(root->right == NULL){
//     root->right = curr;
//   } else {
//     if(rand() % 2){
//       insert(root->left, key);
//     } else {
//       insert(root->right, key);
//     }
//   }
// }

// // Finding the deepest node
// NODE deepestNode(NODE root){
//   if(root == NULL) return NULL;
//   NODE queue[1000];
//   int f = 0, r = 0;
//   queue[r++] = root;
//   NODE temp;
//   while(f < r){
//     temp = queue[f++];
//     if(temp->left) queue[r++] = temp->left;
//     if(temp->right) queue[r++] = temp->right;
//   }
//   return temp;
// }

// // Deleting the deepest node
// void deletedeepest(NODE root, NODE delNode){
//   if(root == NULL) return;
//   if(root->right == delNode){
//     free(root->right);
//     root->right = NULL;
//     return;
//   }
//   if(root->left == delNode){
//     free(root->left);
//     root->left = NULL;
//     return;
//   }
//   if(root->right) deletedeepest(root->right, delNode);
//   if(root->left) deletedeepest(root->left, delNode);
// }

// // Deleting a node
// NODE deleteNode(NODE root, int key){
//   if(root == NULL) return NULL;
//   if(root->data == key){
//     NODE dep = deepestNode(root);
//     root->data = dep->data;
//     deletedeepest(root, dep);
//     return root;
//   }
//   root->left = deleteNode(root->left, key);
//   root->right = deleteNode(root->right, key);
//   return root;
// }

// // Number of nodes
// int noOfNodes(NODE root){
//   if(root==NULL) return 0;
//   return noOfNodes(root->left) + noOfNodes(root->right) + 1;
// }

// // Height of tree
// int height(NODE root){
//   if(root==NULL) return 0;
//   int l = height(root->left);
//   int r = height(root->right);
//   return (l > r ? l : r) + 1;
// }

// // Diameter of tree
// int diameter(NODE root){
//   if(root==NULL) return 0;
//   int lht = height(root->left);
//   int rht = height(root->right);
//   int rootd = lht + rht + 1;
//   int ldia = diameter(root->left);
//   int rdia = diameter(root->right);
//   int max = ldia > rdia ? ldia : rdia;
//   return max > rootd ? max : rootd;
// }

// // Level order traversal
// void levelOrder(NODE root){
//   if(root==NULL) return;
//   NODE queue[1000];
//   int f = 0, r = 0;
//   queue[r++] = root;
//   while(f < r){
//     NODE temp = queue[f++];
//     printf("%d ", temp->data);
//     if(temp->left) queue[r++] = temp->left;
//     if(temp->right) queue[r++] = temp->right;
//   }
// }

// // Inorder traversal
// void inOrder(NODE root){
//   if(root==NULL) return;
//   inOrder(root->left);
//   printf("%d ", root->data);
//   inOrder(root->right);
// }

// int main() {
//   NODE R = create(1);
//   insert(R, 2);
//   insert(R, 3);
//   insert(R, 4);
//   insert(R, 5);
  
//   printf("InOrder Traversal Before Deletion: ");
//   inOrder(R);
//   printf("\n");
  
//   printf("Level Order Traversal: ");
//   levelOrder(R);
//   printf("\n");
  
//   printf("Height: %d\n", height(R));
//   printf("Diameter: %d\n", diameter(R));
//   printf("Number of Nodes: %d\n", noOfNodes(R));
  
//   R = deleteNode(R, 2);
  
//   printf("InOrder Traversal After Deletion: ");
//   inOrder(R);
//   printf("\n");
  
//   return 0;
// }


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val, height;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* NODE;

NODE create(int val) {
    NODE n = (NODE)malloc(sizeof(struct Node));
    n->val = val;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int height(NODE r) {
    if (r == NULL) {
        return 0;
    }
    return r->height;
}

int balanceFactor(NODE root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

// left rotate
NODE lrotate(NODE root) {
    NODE x = root->right;
    if (x == NULL) return root;
    NODE y = x->left;
    x->left = root;
    root->right = y;
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    return x;
}

// right rotate
NODE rrotate(NODE root) {
    NODE x = root->left;
    if (x == NULL) return root;
    NODE y = x->right;
    x->right = root;
    root->left = y;
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    return x;
}

NODE insert(NODE r, int key) {
    if (r == NULL) {
        return create(key);
    }
    if (key < r->val) {
        r->left = insert(r->left, key);
    } else if (key > r->val) {
        r->right = insert(r->right, key);
    } else {
        return r;
    }
    r->height = 1 + (height(r->left) > height(r->right) ? height(r->left) : height(r->right));

    int bf = balanceFactor(r);

    // left left
    if (bf > 1 && key < r->left->val) {
        return rrotate(r);
    }
    // right right
    if (bf < -1 && key > r->right->val) {
        return lrotate(r);
    }
    // left right
    if (bf > 1 && key > r->left->val) {
        r->left = lrotate(r->left);
        return rrotate(r);
    }
    // right left
    if (bf < -1 && key < r->right->val) {
        r->right = rrotate(r->right);
        return lrotate(r);
    }
    return r;
}


NODE minimum(NODE root){
  if(root==NULL) return NULL;
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}

NODE delete(NODE root, int val){
  if(root==NULL) return NULL;
  if(val < root->val){
    root->left = delete(root->left, val);
  } else if(val > root->val){
    root->right = delete(root->right, val);
  } else {
    if(root->left==NULL || root->right==NULL){
      NODE temp = root->left ? root->left : root->right;
      if(temp == NULL){
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }
      free(temp);
    } else {
      NODE min = minimum(root->right);
      root->val = min->val;
      root->left = delete(root->left, min->val);
    }
  }
  if(root == NULL) return root;
  root->height = 1 + ((height(root->left) > height(root->right)) ? height(root->left) : height(root->right));

  int bf = balanceFactor(root);
  if(bf > 1 && balanceFactor(root->left)>=0){
    return rrotate(root);
  }
  if(bf > 1 && balanceFactor(root->left) < 0){
    root->left = lrotate(root->left);
    return rrotate(root);
  }

  if(bf < -1 && balanceFactor(root->right) <= 0)
      return lrotate(root);

  if(bf < -1 && balanceFactor(root->right) > 0){
      root->right = rrotate(root->right);
      return lrotate(root);
  }

  return root;
}

void inorder(NODE r) {
    if (r == NULL) return;
    inorder(r->left);
    printf("%d ", r->val);
    inorder(r->right);
}

int main() {
    NODE R = NULL;
    R = insert(R, 1);
    R = insert(R, 2);
    R = insert(R, 3);
    R = insert(R, 4);
    R = insert(R, 5);
    R = insert(R, 6);
    R = insert(R, 7);
    inorder(R);
    printf("\n"); // Added newline for better output formatting
    R = delete(R, 3);
    inorder(R);
    return 0;
}
