class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = 0;
        // size
        for(int i = 0; i < size(nums); i += 2) n += nums[i];

        vector<int> ans(n, 0);

        // adding the values
        int pre = 0, key = 0;

        for(int i = 0; i < size(nums); i += 2) {
            pre += nums[i];
            for(int j = key; j < pre; j++) ans[j] = nums[i+1];
            key += nums[i];
        }

        return ans;
    }
};