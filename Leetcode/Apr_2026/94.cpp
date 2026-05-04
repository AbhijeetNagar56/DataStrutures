class Solution {
public:

    void inOrder(TreeNode* root, vector<int>& stack) {
        if(root == NULL) return;
        inOrder(root->left, stack);
        stack.push_back(root->val);
        inOrder(root->right, stack);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inOrder(root, ans);

        return ans;

    }
};