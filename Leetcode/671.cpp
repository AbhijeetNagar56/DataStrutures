class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        
        int minVal = root->val;
        int secondMin = -1;
        
        std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            
            if (node->val > minVal) {
                if (secondMin == -1 || node->val < secondMin) {
                    secondMin = node->val;
                }
            }
            
            dfs(node->left);
            dfs(node->right);
        };
        
        dfs(root);
        return secondMin;
    }
};