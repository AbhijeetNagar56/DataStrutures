class Solution {
public:
    int binary(vector<int>& arr, int l, int r, int t) {
        if(l >= r && arr[l] != t) {
            return -1;
        }
        int mid = l + (r - l) / 2;
        if(arr[mid] == t) {
            return mid;
        } else if(arr[mid] < t) {
            return binary(arr, mid + 1, r, t);
        } else {
            return binary(arr, l, mid - 1, t);
        }
    }
    int search(vector<int>& nums, int target) {
        return binary(nums, 0, nums.size() - 1, target);
    }
};