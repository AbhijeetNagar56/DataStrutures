class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        int count = 0;
        for(int i=n-1; i>=0; i--) {
            if(nums[i] == k) {
                count++;
            }
            for(int j=i-1; j>=0; j--) {
                if(nums[i]-nums[j] == k) {
                    count++;
                }
            }
        }
        return count;
    }
};