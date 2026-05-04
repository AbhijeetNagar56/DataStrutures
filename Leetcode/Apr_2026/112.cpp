class Solution {
public:
    bool isEqual(TreeNode* root, int sum, int target) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) {
            if(sum + root->val == target) return true;
            return false;
        }
        return isEqual(root->left, sum + root->val, target) || isEqual(root->right, sum + root->val, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isEqual(root, 0, targetSum);
    }
};