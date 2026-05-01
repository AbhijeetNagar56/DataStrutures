class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int maxSum = 0, n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 1; i += 2) {
            maxSum += min(nums[i], nums[i + 1]);
        }

        return maxSum;
    }
};