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

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix_count = {{0, 1}};
        int prefix_sum = 0, count = 0;
        for(int i=0; i<n; i++) {
            prefix_sum += nums[i];
            if(prefix_count.find(prefix_sum-k) != prefix_count.end()) {
                count += prefix_count[prefix_sum-k];
            }
            prefix_count[prefix_sum]++;
        }
        return count;
    }
};