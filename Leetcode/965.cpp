class Solution {
public:
    bool helper(TreeNode* root, int val) {
        if(root == NULL) return true;

        if(root->val != val) return false;

        return helper(root->left, val) && helper(root->right, val);
    }
    bool isUnivalTree(TreeNode* root) {
        int uni_val = root->val;
        return helper(root, uni_val);
    }
};