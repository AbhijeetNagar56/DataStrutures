// hash map + sort
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

// two pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int s = 2;
        for(int f = 2; f < nums.size(); f++) {
            if(nums[f] != nums[s - 2]) {
                nums[s] = nums[f];
                s++;
            }
        }


        return s;
    }
};