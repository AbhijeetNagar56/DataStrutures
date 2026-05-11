class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> cts;
        vector<int> ans;
        for(int n: nums) cts[n]++;

        for(auto& pair: cts) {
            if(pair.second == 1) {
                ans.push_back(pair.first);
            } else {
                ans.push_back(pair.first);
                ans.push_back(pair.first);
            }
        }

        sort(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); i++) {
            nums[i] = ans[i];
        }

        return ans.size();

    }
};