class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            if (i >= k - 1) {
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> deq;
        for (int i = 0; i < n; i++) {
            if (!deq.empty() && deq.front() <= i - k) 
                deq.pop_front();
            while (!deq.empty() && nums[deq.back()] <= nums[i]) 
                deq.pop_back();
            deq.push_back(i);
            if (i >= k - 1) 
                ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};