class Solution {
public:
    bool path(TreeNode* r, vector<TreeNode*>& a, TreeNode* n) {
        if(r == NULL) return false;
        a.push_back(r);

        if(r == n || path(r->left, a, n) || path(r->right, a, n)) {
            return true;
        }

        a.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;


        if(!path(r, path1, p) || !path(r, path2, q)) {
            return nullptr;
        }

        int i = 0;
        for(i = 0; i < min(path1.size(), path2.size()); i++) {
            if(path1[i] != path2[i]) return path1[i - 1];
        } 
        

        return path1[i - 1];
    }
};