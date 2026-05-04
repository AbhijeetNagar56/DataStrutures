class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Max = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            Max = max(Max, curr);
            for (int j = i + 1; j < nums.size(); j++) {
                curr += nums[j];
                Max = max(Max, curr);
            }
        }

        return Max;
    }
};

// optimized solution using Kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], total = 0;

        for (int n : nums) {
            if (total < 0) {
                total = 0;
            }

            total += n;
            res = max(res, total);
        }

        return res;
    }
};