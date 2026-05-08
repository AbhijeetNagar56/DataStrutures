#include <iostream>
#include <vector>
#include <algorithm>

long long maxSubarraySum(std::vector<int>& nums) {
    long long max_so_far = nums[0];
    long long current_max = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        // Decide: Start over at nums[i] or keep adding?
        current_max = std::max((long long)nums[i], current_max + nums[i]);
        
        // Update the global maximum
        max_so_far = std::max(max_so_far, current_max);
    }
    return max_so_far;
}