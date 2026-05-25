class Solution {
public:
    vector<vector<int>> ans;

    void sumSeq(TreeNode* root, int target, int curr, vector<int>& arr) {
        if(root == NULL) return;

        curr += root->val;
        arr.push_back(root->val);
        sumSeq(root->left, target, curr, arr);
        sumSeq(root->right, target, curr, arr);


        if(root->left == NULL && root->right == NULL) {
            if(curr == target) {
                ans.push_back(arr);
            }
        }

        arr.pop_back();
        curr -= root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> s;
        
        sumSeq(root, targetSum, 0, s);

        return ans;
    }
};