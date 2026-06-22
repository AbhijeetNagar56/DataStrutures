#include <iostream>
#include <queue>
using namespace std;

enum Color { RED, BLACK };

class node {
public:
    int val;
    Color color;
    node *left, *right, *parent;

    node(int val) {
        this->val = val;
        this->color = RED; // Rules dictate new nodes are inserted as RED
        this->left = this->right = this->parent = nullptr;
    }
};

class RedBlackTree {
private:
    node* root;

    // Standard BST Insertion helper that returns the newly created node
    node* bstInsert(node* r, node* temp) {
        if (r == nullptr) return temp;

        if (temp->val < r->val) {
            r->left = bstInsert(r->left, temp);
            r->left->parent = r;
        } else if (temp->val > r->val) {
            r->right = bstInsert(r->right, temp);
            r->right->parent = r;
        }
        return r;
    }

    void leftRotate(node*& root, node*& x) {
        node* y = x->right;
        x->right = y->left;

        if (x->right != nullptr)
            x->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(node*& root, node*& y) {
        node* x = y->left;
        y->left = x->right;

        if (x->right != nullptr)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    // Fixes violations caused by inserting a RED node
    void fixViolation(node*& root, node*& ptr) {
        node* parent_ptr = nullptr;
        node* grandparent_ptr = nullptr;

        while ((ptr != root) && (ptr->color != BLACK) && (ptr->parent->color == RED)) {
            parent_ptr = ptr->parent;
            grandparent_ptr = ptr->parent->parent;

            /* Case A: Parent of ptr is left child of Grandparent */
            if (parent_ptr == grandparent_ptr->left) {
                node* uncle_ptr = grandparent_ptr->right;

                /* Case 1: Uncle is also RED -> Only Recoloring needed */
                if (uncle_ptr != nullptr && uncle_ptr->color == RED) {
                    grandparent_ptr->color = RED;
                    parent_ptr->color = BLACK;
                    uncle_ptr->color = BLACK;
                    ptr = grandparent_ptr;
                } 
                else {
                    /* Case 2: ptr is right child of its parent -> Left-rotation needed */
                    if (ptr == parent_ptr->right) {
                        leftRotate(root, parent_ptr);
                        ptr = parent_ptr;
                        parent_ptr = ptr->parent;
                    }

                    /* Case 3: ptr is left child of its parent -> Right-rotation needed */
                    rightRotate(root, grandparent_ptr);
                    swap(parent_ptr->color, grandparent_ptr->color);
                    ptr = parent_ptr;
                }
            }
            /* Case B: Parent of ptr is right child of Grandparent */
            else {
                node* uncle_ptr = grandparent_ptr->left;

                /* Case 1: Uncle is also RED -> Only Recoloring needed */
                if ((uncle_ptr != nullptr) && (uncle_ptr->color == RED)) {
                    grandparent_ptr->color = RED;
                    parent_ptr->color = BLACK;
                    uncle_ptr->color = BLACK;
                    ptr = grandparent_ptr;
                } 
                else {
                    /* Case 2: ptr is left child of its parent -> Right-rotation needed */
                    if (ptr == parent_ptr->left) {
                        rightRotate(root, parent_ptr);
                        ptr = parent_ptr;
                        parent_ptr = ptr->parent;
                    }

                    /* Case 3: ptr is right child of its parent -> Left-rotation needed */
                    leftRotate(root, grandparent_ptr);
                    swap(parent_ptr->color, grandparent_ptr->color);
                    ptr = parent_ptr;
                }
            }
        }
        root->color = BLACK; // Root must stay black
    }

public:
    RedBlackTree() { root = nullptr; }

    void insert(const int& data) {
        node* temp = new node(data);
        root = bstInsert(root, temp);
        fixViolation(root, temp);
    }

    void levelOrder() {
        if (root == nullptr) return;

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                node* curr = q.front();
                q.pop();

                string col = (curr->color == RED) ? "(R)" : "(B)";
                cout << curr->val << col << " ";

                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            cout << endl;
        }
    }
};

int main() {
    RedBlackTree tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);

    cout << "Level Order Traversal of Red-Black Tree:\n";
    cout << "Format: value(Color)\n\n";
    tree.levelOrder();

    return 0;
}