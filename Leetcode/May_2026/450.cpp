class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left) {
                TreeNode* right = root->right;
                delete root;
                return right;
            } 
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }

            TreeNode* right = root->right;
            while(right->left) right = right->left;
            root->val = right->val;
            root->right = deleteNode(root->right, right->val);
        }

        return root;
    }
};