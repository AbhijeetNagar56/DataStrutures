class Solution {
public:
    void sum(TreeNode* root, int& s) {
        if(root == NULL) return;
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL) s += root->left->val;
        sum(root->left, s);
        sum(root->right, s);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum_of_leaves = 0;

        sum(root, sum_of_leaves);

        return sum_of_leaves;
    }
};