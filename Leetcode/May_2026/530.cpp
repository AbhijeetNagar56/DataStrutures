class Solution {
public:
    int diff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return 0;

        // root lefts rightmost
        if(root->left) {
            TreeNode* tmp = root->left;
            while(tmp->right) {
                tmp = tmp->right;
            }
            diff = min(diff, abs(root->val - tmp->val));
        }
        // root rights leftmost
        if(root->right) {
            TreeNode* tmp = root->right;
            while(tmp->left) {
                tmp = tmp->left;
            }
            diff = min(diff, abs(root->val - tmp->val));
        }

        getMinimumDifference(root->left);
        getMinimumDifference(root->right);

        return diff;
    }
};