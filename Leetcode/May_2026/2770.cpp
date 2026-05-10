// greedy approach
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size(), i = 0; // starting position
        int step = 0, key = nums[i];

        for (int j = 1; j < n; j++) {
            if(abs(key - nums[j]) <= target) {
                step++;
                key = nums[j];
                i = j;
            }
        }

        if(i != n - 1) return -1;

        return step;
    }
};

// dynamic programming
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if(dp[i] != -1 && abs(nums[i] - nums[j]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};