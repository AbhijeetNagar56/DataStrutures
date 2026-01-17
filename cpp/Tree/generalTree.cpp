#include <iostream>
using namespace std;

class node {
    public:
        int val;
        node* left;
        node* right;
        node(int data) {
            this->val = data;
            this->left = this->right = NULL;
        }
};

class tree {
    public:
        node* root;  // Changed: should be node* (pointer), not node
        
        tree(int rootVal) {
            this->root = new node(rootVal);  // Changed: allocate memory with 'new'
        }
        
        void insert(node* root, int key) {  // Changed: parameter should be node* (pointer)
            node* newNode = new node(key);  // Changed: allocate memory with 'new'
            
            if(root->left == NULL) {
                root->left = newNode;
            } else if(root->right == NULL) {  // Changed: 'else-if' to 'else if'
                root->right = newNode;
            } else {
                if(root->left->left == NULL || root->left->right == NULL) {
                    insert(root->left, key);
                } else {
                    insert(root->right, key);
                }
            }
        }

        void inorder(node* root) {  // Changed: parameter should be node* (pointer)
            if(root == NULL) return;
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
};

int main () {
    tree Tree1(0);
    Tree1.insert(Tree1.root, 2);
    Tree1.insert(Tree1.root, 3);
    Tree1.inorder(Tree1.root);
    cout << endl << "hello" << endl;
    return 0;
}