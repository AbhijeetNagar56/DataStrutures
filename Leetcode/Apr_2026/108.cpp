class Solution {
public:
    TreeNode* insert(vector<int>& nums, int low, int high) {
        if (low > high) return nullptr;
        
        int mid = low + (high - low) / 2;
        TreeNode* new_node = new TreeNode(nums[mid]);
        
        new_node->left = insert(nums, low, mid - 1);
        new_node->right = insert(nums, mid + 1, high);
        
        return new_node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(nums, 0, nums.size() - 1);
    }
};