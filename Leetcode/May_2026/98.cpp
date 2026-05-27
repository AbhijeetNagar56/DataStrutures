class Solution {
public:
    bool isValidBST(TreeNode* r) {
        return valid(r, LONG_MIN, LONG_MAX);
    }
private:
    bool valid(TreeNode* n, long minimum, long maximum) {
        if(!n) return true;

        if(!(n->val > minimum && n->val < maximum)) return false;

        bool left = valid(n->left, minimum, n->val);
        bool right = valid(n->right, n->val, maximum);

        return left && right;
    }
};