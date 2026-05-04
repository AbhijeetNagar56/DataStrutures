class Solution {
public:
    void postOrder(TreeNode* root, vector<int>& stack) {
        if(root == NULL) return;
        
        postOrder(root->left, stack);
        postOrder(root->right, stack);
        stack.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        postOrder(root, ans);

        return ans;

    }
};