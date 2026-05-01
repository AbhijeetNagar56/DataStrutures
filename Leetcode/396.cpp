// brute force, TLE
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), start = 0, max_score = -1e9;

        while(true) {
            int f_out = 0;
            for (int i = 0; i < n; i++) {
                f_out += i * nums[(start + i) % n];
            }
            max_score = max(max_score, f_out);

            start == 0 ? start = n - 1 : start--;
            if (start == 0) break;
        }

        return max_score;
    }
};


// optimal solution, O(n)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long sum = 0;
        long F = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long)i * nums[i];
        }

        long ans = F;

        for (int k = 1; k < n; k++) {
            F = F + sum - (long)n * nums[n - k];
            ans = max(ans, F);
        }

        return (int)ans;
    }
};