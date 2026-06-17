// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {

//         return backtrack(0, 0, target, nums);
        
//     }

//     int backtrack(int i, int curr, int target, vector<int>& nums) {
//         if(i==nums.size()) {
//             return target==curr ? 1 : 0;
//         }
//         return backtrack(i+1, curr+nums[i], target, nums) + backtrack(i+1, curr-nums[i], target, nums);
//     }
// };


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (auto &p : dp[i]) {
                dp[i + 1][p.first + nums[i]] += p.second;
                dp[i + 1][p.first - nums[i]] += p.second;
            }
        }
        return dp[n][target];
    }
};
