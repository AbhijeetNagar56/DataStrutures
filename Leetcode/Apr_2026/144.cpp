class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& stack) {
        if(root == NULL) return;
        stack.push_back(root->val);
        preOrder(root->left, stack);
        preOrder(root->right, stack);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preOrder(root, ans);

        return ans;

    }
};