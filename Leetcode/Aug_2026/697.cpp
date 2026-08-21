class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> ind;

        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            ind[num].push_back(i);
        }

        int minLen = INT_MAX;
        int maxFreq = 0;

        for(auto& it: ind) {
            
            int currFreq = it.second.size();
            int currLen = it.second[currFreq-1] - it.second[0] + 1;

            if(currFreq > maxFreq) {
                maxFreq = currFreq;
                minLen = currLen;
            } else if(currFreq == maxFreq) {
                minLen = min(minLen, currLen);
            }
        }

        return minLen;
    }
};