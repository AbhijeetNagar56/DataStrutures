class Solution {
public:
    unordered_map<int, int> p;
    
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        int comp = k - root->val;
        if(p.find(comp) != p.end()) {
            return true;
        } else {
            p[root->val] = 0;
        }

        return findTarget(root->left, k) || findTarget(root->right, k);

    }
};