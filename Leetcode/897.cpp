class Solution {
public:
    void insert(TreeNode* root, int val) {
        TreeNode* new_node = new TreeNode(val);
        while(root->right != NULL) root = root->right;
        root->right = new_node;
    }

    void helper(TreeNode* original, TreeNode* copy) {
        if(original == NULL) return;
        helper(original->left, copy);
        insert(copy, original->val);
        helper(original->right, copy);
    }


    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* root_new = new TreeNode(0);
        helper(root, root_new);

        return root_new->right;

    }
};