#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int val;
	node* right;
	node* left;
	node(int val) {
		this->val = val;
		this->left = this->right = nullptr;
	}
};


class bst {
public:
	node* root;
	bst(int r_val) {
		this->root = new node(r_val);
	}
	void insert(node* r, int val) {
		node* newNode = new node(val);
		if(this->root == nullptr) {
			this->root = newNode;
			return;
		}
		if(r->val > val) {
			if(r->left == nullptr) {
				r->left = newNode;
				return;
			}
			insert(r->left, val);
		} else {
			if(r->right == nullptr) {
				r->right = newNode;
				return;
			}
			insert(r->right, val);
		}
	}
	bool search(node* r, int key) {
		if(r == nullptr) return false;
		return r->val == key || search(r->left, key) || search(r->right, key);
	}
	node* deleteNode(node* r, int key) {
		if(r == NULL) return r;
		if(r->val > key) {
			r->left = deleteNode(r->left, key);
		} else if(r->val < key) {
			r->right = deleteNode(r->right, key);
		} else {
			if(!r->left) {
				node* tmp = r->right;
				delete r;
				return tmp;
			}
			if(!r->right) {
				node* tmp = r->left;
				delete r;
				return tmp;
			}
			node* tmp = r->right;
			while(tmp->left) tmp = tmp->left;
			r->val = tmp->val;
			r->right = deleteNode(r->right, tmp->val);
		}
		return r;
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
			int n = q.size();
			for(int i = 0; i < n; i++) {
				node* curr = q.front();
				cout << curr->val << " ";
				q.pop();
				if(curr->left) q.push(curr->left);
				if(curr->right) q.push(curr->right);
			}
			cout << endl;
		}
    }
};
int main() {
	// bst
	bst t(10);
	t.insert(t.root, 5);
	t.insert(t.root, 15);
	t.insert(t.root, 3);
	t.insert(t.root, 7);
	t.insert(t.root, 12);
	t.insert(t.root, 18);
	t.inorder(t.root);
	cout << endl;
	t.preorder(t.root);
	cout << endl;
	t.postorder(t.root);
	cout << endl;
	t.levelOrder(t.root);
	t.root = t.deleteNode(t.root, 5);
	t.levelOrder(t.root);
	return 0;
}
