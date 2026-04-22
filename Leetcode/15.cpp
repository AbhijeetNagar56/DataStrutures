vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    // Sorting
    sort(nums.begin(), nums.end());

    // result array
    vector<vector<int>> result;

    // Two pointer logic
    for(int i = 0; i < n; i++) {

        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int total = nums[left] + nums[right] + nums[i];

            if(total > 0) {
                right--;
            } else if (total < 0) {
                left++;
            } else {
                result.push_back({nums[left], nums[i], nums[right]});
                left++;

                while (nums[left] == nums[left-1] && left < right) {
                    left++;
                }
            }
        }
    }
    
    return result;
}