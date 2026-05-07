class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        vector<int> res;
        int thres = nums.size() / 3;

        for (int num: nums) count[num]++;

        for(auto& pair: count) if(pair.second > thres) res.push_back(pair.first);

        return res;
    }
};