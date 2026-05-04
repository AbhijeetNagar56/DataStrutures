class Solution {
public:
    void rec_sol(TreeNode* root, int& count) {
        if(root == NULL) return;

        if(root!= NULL) count++;

        rec_sol(root->left, count);
        rec_sol(root->right, count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;

        rec_sol(root, count);

        return count;
    }
};