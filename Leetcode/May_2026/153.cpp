class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        for(int i = 0; i < n; i++) if(nums[i] < nums[l]) l = i;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] >= nums[l]) { // left half
                if(nums[l] > nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                r = mid;
            }


        }

        return nums[l]; // l or r points to same element
    }
};