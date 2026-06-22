#include <iostream>
#include <queue>
#include <string>
#include <algorithm> // For max()
using namespace std;

class node {
public:
    int val;
    int ht;
    node* right;
    node* left;
    node(int val) {
        this->val = val;
        this->ht = 1; // New nodes are leaves, so initial height is 1
        this->left = this->right = nullptr;
    }
};

class avl {
public:
    node* root;
    avl(int r_val) {
        this->root = new node(r_val);
    }

    // Helper to get height safely
    int height(node* r) {
        if (r == nullptr) return 0;
        return r->ht;
    }

    // Helper to get balance factor
    int getBalance(node* r) {
        if (r == nullptr) return 0;
        return height(r->left) - height(r->right);
    }

    // Rotations
    node* left_rotate(node* r) {
        node* new_root = r->right;
        node* left_child_of_new = new_root->left;

        // Perform rotation
        new_root->left = r;
        r->right = left_child_of_new;

        // Update heights
        r->ht = max(height(r->left), height(r->right)) + 1;
        new_root->ht = max(height(new_root->left), height(new_root->right)) + 1;

        return new_root;
    }

    node* right_rotate(node* r) {
        node* new_root = r->left;
        node* right_child_of_new = new_root->right;

        // Perform rotation
        new_root->right = r;
        r->left = right_child_of_new;

        // Update heights
        r->ht = max(height(r->left), height(r->right)) + 1;
        new_root->ht = max(height(new_root->left), height(new_root->right)) + 1;

        return new_root;
    }

    // Insert Function
    node* insert(node* r, int val) {
        // 1. Perform standard BST insertion
        if (r == nullptr) return new node(val);

        if (val < r->val) {
            r->left = insert(r->left, val);
        } else if (val > r->val) {
            r->right = insert(r->right, val);
        } else {
            return r; // Duplicate values not allowed in this AVL
        }

        // 2. Update height of this ancestor node
        r->ht = 1 + max(height(r->left), height(r->right));

        // 3. Get the balance factor to check if it became unbalanced
        int balance = getBalance(r);

        // --- 4 Balancing Cases ---
        
        // Left Left Case
        if (balance > 1 && val < r->left->val) {
            return right_rotate(r);
        }

        // Right Right Case
        if (balance < -1 && val > r->right->val) {
            return left_rotate(r);
        }

        // Left Right Case
        if (balance > 1 && val > r->left->val) {
            r->left = left_rotate(r->left);
            return right_rotate(r);
        }

        // Right Left Case
        if (balance < -1 && val < r->right->val) {
            r->right = right_rotate(r->right);
            return left_rotate(r);
        }

        return r; // Return the unchanged/balanced pointer
    }
    
    // Helper to find the node with the minimum value (used in deletion)
    node* minValueNode(node* n) {
        node* current = n;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Delete Function
    node* deleteNode(node* r, int key) {
        // 1. Perform standard BST delete
        if (r == nullptr) return r;

        if (key < r->val) {
            r->left = deleteNode(r->left, key);
        } else if (key > r->val) {
            r->right = deleteNode(r->right, key);
        } else {
            // Node with only one child or no child
            if ((r->left == nullptr) || (r->right == nullptr)) {
                node* temp = r->left ? r->left : r->right;

                // No child case
                if (temp == nullptr) {
                    temp = r;
                    r = nullptr;
                } else { // One child case
                    *r = *temp; // Copy the contents of the non-empty child
                }
                delete temp;
            } else {
                // Node with two children: Get the inorder successor
                node* temp = minValueNode(r->right);

                // Copy the inorder successor's data to this node
                r->val = temp->val;

                // Delete the inorder successor
                r->right = deleteNode(r->right, temp->val);
            }
        }

        // If the tree had only one node then return
        if (r == nullptr) return r;

        // 2. Update height of current node
        r->ht = 1 + max(height(r->left), height(r->right));

        // 3. Get balance factor
        int balance = getBalance(r);

        // --- Balancing Cases ---
        
        // Left Left Case
        if (balance > 1 && getBalance(r->left) >= 0) {
            return right_rotate(r);
        }

        // Left Right Case
        if (balance > 1 && getBalance(r->left) < 0) {
            r->left = left_rotate(r->left);
            return right_rotate(r);
        }

        // Right Right Case
        if (balance < -1 && getBalance(r->right) <= 0) {
            return left_rotate(r);
        }

        // Right Left Case
        if (balance < -1 && getBalance(r->right) > 0) {
            r->right = right_rotate(r->right);
            return left_rotate(r);
        }

        return r;
    }

    // Search
    bool search(node* r, int key) {
        if (r == nullptr) return false;
        if (r->val == key) return true;
        return key < r->val ? search(r->left, key) : search(r->right, key);
    }

    // Traversals
    void inorder(node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void levelOrder(node* root) {
        if (root == nullptr) return;
        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                node* curr = q.front();
                cout << curr->val << " ";
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            cout << endl;
        }
    }
};

int main() {
    avl t(10);
    
    // Crucial change: Since insert modifies and returns the new tree structure roots,
    // we must catch the returned root pointer to keep the class sync'd.
    t.root = t.insert(t.root, 5);
    t.root = t.insert(t.root, 15);
    t.root = t.insert(t.root, 3);
    t.root = t.insert(t.root, 7);
    t.root = t.insert(t.root, 12);
    t.root = t.insert(t.root, 18);

    cout << "Level Order before deletion:" << endl;
    t.levelOrder(t.root);

    // Let's test deletion
    t.root = t.deleteNode(t.root, 15);
    cout << "\nLevel Order after deleting 15:" << endl;
    t.levelOrder(t.root);

    return 0;
}