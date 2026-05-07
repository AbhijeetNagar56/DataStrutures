class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        for(int num : nums) total_sum += num;

        int left_sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            // Right sum = Total - Left - Current Element
            int right_sum = total_sum - left_sum - nums[i];
            
            if(left_sum == right_sum) {
                return i;
            }
            
            // Update left_sum for the next iteration
            left_sum += nums[i];
        }

        return -1;
    }
};