class Solution {
public:
    string tree2str(TreeNode* r) {
        if(r == NULL) return "";
        string ans = ct(r);
        return ans.substr(1, ans.size() - 2);

    }
private:
    string ct(TreeNode* r) {
        if(r == NULL) return "";

        string lt = "", rt = "";
        if(r->left || r->right) {
            lt = ct(r->left);
            rt = ct(r->right);
            if(lt == "") lt = "()";
        }

        return "(" + to_string(r->val) + lt + rt + ")";
    }
};