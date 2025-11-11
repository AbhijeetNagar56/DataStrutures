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
