class Solution {
public:
    int totalTilt = 0; // Global variable to store the sum of all tilts

    int findTilt(TreeNode* root) {
        calculateTilt(root);
        return totalTilt;
    }

private:
    int calculateTilt(TreeNode* root) {
        if (root == NULL) return 0;

        // 1. Recursively get sum of left and right subtrees
        int leftSum = calculateTilt(root->left);
        int rightSum = calculateTilt(root->right);

        // 2. Calculate tilt for current node
        int tilt = abs(leftSum - rightSum);
        
        // 3. Add to total tilt
        totalTilt += tilt;

        // 4. Return the sum of the current subtree
        return root->val + leftSum + rightSum;
    }
};