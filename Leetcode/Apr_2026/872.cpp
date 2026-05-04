class Solution {
public:
    void sequence(TreeNode* root, vector<int>& list) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) list.push_back(root->val);
        sequence(root->left, list);
        sequence(root->right, list);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;

        sequence(root1, seq1);
        sequence(root2, seq2);

        if(seq1.size() != seq2.size()) return false;

        for(int i = 0; i < seq1.size(); i++) {
            if(seq1[i] != seq2[i]) return false;
        }

        return true;
    }
};