// sorted array only
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = n - 1;

        while(l < r) {
            int curr = nums[l] + nums[r];

            if(curr == target)
                break;
            else if(curr >target)
                r--;
            else
                l++;

        }

        vector<int> ans;
        ans.push_back(l);
        ans.push_back(r);

        return ans;
    }
};

// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }

        return ans;
    }
};

// using hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp; 

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                ans.push_back(mp[complement]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};
