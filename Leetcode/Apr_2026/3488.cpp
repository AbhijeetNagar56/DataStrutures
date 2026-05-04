class Solution {
public:
    int findIndex(vector<int>& nums, int target, int startIndex) {
        int n = nums.size();
        int minDistance = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {

                int d = abs(startIndex - i);

                int circularDist = min(d, n - d);
                
                if (minDistance == -1 || circularDist < minDistance) {
                    minDistance = circularDist;
                }
            }
        }

        return minDistance;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int s = queries.size();
        vector<int> answer(s, -1);

        for (int q = 0; q < s; q++) {
            // target is nums[queries[q]], startIndex is queries[q]
            answer[q] = findIndex(nums, nums[queries[q]], queries[q]);
        }

        return answer;
    }
};