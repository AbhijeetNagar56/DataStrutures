class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;

        int arr = 0;
        for(int n: nums) arr+=n;

        return sum - arr;
    }
};