#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int val;
    node *left, *right;
    node(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

class tree {
public:
    node* root;

    tree(int rootVal) {
        this->root = new node(rootVal);
    }

    void insert(node* root, int key) {
        node* newNode = new node(key);
        if(root->left == nullptr) {
            root->left = newNode;
        } else if(root->right == nullptr) {
            root->right = newNode;
        } else {
            if(root->left->left == nullptr || root->left->right == nullptr) {
                insert(root->left, key);
            } else {
                insert(root->right, key);
            }
        }
    }

    void deletDeepest(node* root, node* dNode) {
        queue<node*> q;
        q.push(root);

        node* curr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();

            // If current node is the deepest
            // node, delete it
            if (curr == dNode) {  
                curr = nullptr;
                delete (dNode);
                return;
            }

            // Check the right child first
            if (curr->right) {
            
                // If right child is the deepest
                // node, delete it
                if (curr->right == dNode) {
                    curr->right = nullptr;
                    delete (dNode);
                    return;
                } 
                q.push(curr->right);
            }

            // Check the left child
            if (curr->left) {
            
                // If left child is the deepest 
                // node, delete it
                if (curr->left == dNode) {
                    curr->left = nullptr;
                    delete (dNode);
                    return;
                } 
                q.push(curr->left);
            }
        }
    }

    // Function to delete the node with the given key
    node* deletion(node* root, int key) {
    
        // If the tree is empty, return null
        if (root == nullptr)
            return nullptr;

        // If the tree has only one node
        if (root->left == nullptr && root->right == nullptr) {
        
            // If the root node is the key, delete it
            if (root->val == key)
                return nullptr;
            else
                return root;
        }

        queue<node*> q;
        q.push(root);

        node* curr;
        node* keyNode = nullptr;

        // Level order traversal to find the deepest
        // node and the key node
        while (!q.empty()) {
            curr = q.front();
            q.pop();

            // If current node is the key node
            if (curr->val == key)
                keyNode = curr;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        // If key node is found, replace its val
        // with the deepest node
        if (keyNode != nullptr) {
        
            // Store the val of the deepest node
            int x = curr->val;  
        
            // Replace key node val with deepest
            // node's val
            keyNode->val = x;  
        
            // Delete the deepest node
            deletDeepest(root, curr);  
        }
        return root;
    }

    bool search(node* root, int key) {
    if(root == nullptr) return false;
    if(root->val == key) return true;
    return search(root->left, key) || search(root->right, key);
    }

    void inorder(node* root) {
        if(root == nullptr) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void preorder(node* root) {
        if(root == nullptr) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
    void postorder(node* root) {
        if(root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
	void levelOrder(node* root) {
		queue<node*> q;
		q.push(root);

		while(!q.empty()) {
			node* curr = q.front();
			cout << curr->val << " ";
			q.pop();
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}
    }
		
};

int main () {
    tree Tree1(0);
    Tree1.insert(Tree1.root, 2);
    Tree1.insert(Tree1.root, 3);
    // Tree1.inorder(Tree1.root);
    // cout << endl;
    // Tree1.preorder(Tree1.root);
    // cout << endl;
    // Tree1.postorder(Tree1.root);
    // cout << endl;

    // Tree1.deletion(Tree1.root, 2);
    // Tree1.inorder(Tree1.root);
    Tree1.levelOrder(Tree1.root);
    return 0;
}
