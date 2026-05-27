class Solution {
public:
    int total_sum = 0;
    int curr = 0;
    void sum(TreeNode* r) {
        if(r == NULL) return;


        curr = curr * 10 + r->val;

        if(r->left == NULL && r->right == NULL) {
            total_sum += curr;
        }
        
        sum(r->left);
        sum(r->right);

        curr = (curr - r->val) / 10;
    }
    int sumNumbers(TreeNode* root) {
        sum(root);
        return total_sum;
    }
};