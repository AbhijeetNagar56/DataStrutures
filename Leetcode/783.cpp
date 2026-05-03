class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);

    }
    int minDiffInBST(TreeNode* root) {
        vector<int> list;
        

        inOrder(root, list);
        int val = list[1] - list[0];

        for(int i = 0; i < list.size() - 1; i++) {
            val = min(val, list[i+1] - list[i]);
        }

        return val;
    }
};