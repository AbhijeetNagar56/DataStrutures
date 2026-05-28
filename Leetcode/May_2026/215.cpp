class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> mh;

        for(int n: nums) {
            mh.push(n);
        }

        while(k - 1) {
            mh.pop();
            k--;
        }

        return mh.top();

        // // sorting solution
        // sort(nums.begin(), nums.end(), [](int a, int b) {
        //     return a > b;
        // });

        // return nums[k - 1];
    }
};