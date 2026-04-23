// Brute Force Solution
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);

        for (int i = 0; i < n; i++) {
            int key = nums[i];
            for (int j = 0; j < n; j++) {
                if(i == j) continue;
                if(nums[j] == key) arr[i] += abs(i - j);
            }
        }

        return arr;


    }
};