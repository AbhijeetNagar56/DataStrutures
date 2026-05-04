class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<int> pre = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];

            if(interval[0] <= pre[1]) {
                pre[1] = max(pre[1], interval[1]);
            } else {
                res.push_back(pre);
                pre = interval;
            }
        }

        res.push_back(pre);

        return res;

    }
};