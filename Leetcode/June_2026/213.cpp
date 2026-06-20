class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        // 0 to n-1
        vector<int> dp(n-1, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);

        for(int i=2; i<n-1; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        // 1 to n
        vector<int> dpc(n-1, 0);
        dpc[0] = nums[1];
        dpc[1] = max(nums[2], dpc[0]);

        for(int i=2; i<n-1; i++) {
            dpc[i] = max(dpc[i-1], nums[i+1] + dpc[i-2]);
        }

        return max(dp.back(), dpc.back());
    }
};
