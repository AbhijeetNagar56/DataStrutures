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