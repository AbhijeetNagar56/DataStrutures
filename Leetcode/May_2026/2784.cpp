class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size() == 1) return false;
        sort(nums.begin(), nums.end());

        if(nums.size() != nums[nums.size() - 1] + 1) return false;

        for(int i = 1; i < nums.size() - 1; i++) if(nums[i] - nums[i - 1] != 1) return false;

        if(nums[nums.size() - 1] != nums[nums.size() - 2]) return false;

        return true;
    }
};