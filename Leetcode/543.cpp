class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);

        int rootDiameter = height(root->left) + height(root->right);

        return max(rootDiameter, max(left, right));
    }
};