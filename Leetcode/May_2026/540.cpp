class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if(n == 1) return nums[0];

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if(mid == n - 1 && nums[n - 1] == nums[n - 2]) return nums[mid];

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

            if(mid % 2 == 0) { // even parted
                if(nums[mid] == nums[mid - 1]) { // left
                    r = mid - 1;
                } else { // right
                    l = mid + 1;
                }
            } else {
                if(nums[mid] == nums[mid - 1]) { // left
                    l = mid + 1;
                } else { // right
                    r = mid - 1;
                }
            }

        }

        return -1;
    }
};