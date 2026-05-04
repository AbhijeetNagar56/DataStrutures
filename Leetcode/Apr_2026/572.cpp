class Solution {
public:
    bool isEqual(TreeNode* t, TreeNode* s) {
        if(t == NULL && s == NULL) return true;
        if(t == NULL || s == NULL) return false;
        return t->val == s->val && isEqual(t->left, s->left) && isEqual(t->right, s->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(subRoot == NULL) return true;
        
        if(isEqual(root, subRoot)) return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};