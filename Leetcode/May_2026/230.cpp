class Solution {
public:
    void treeToArray(TreeNode* r, vector<int>& a) {
        if(r == NULL) return;

        treeToArray(r->left, a);
        a.push_back(r->val);
        treeToArray(r->right, a);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> element;
        treeToArray(root, element);

        return element[k - 1];
    }
};