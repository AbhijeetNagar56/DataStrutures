// sorting
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;
        sort(nums.begin(), nums.end());
        int longest = 0, curr = 0, last = nums[0]-1;
        for(auto& num: nums) {
            if(num == last+1) {
                curr++;
                last=num;
            } else if(num != last) {
                curr = 1;
                last = num;
            }
            longest = max(longest, curr);
        }
        return longest;
    }
};

// set method
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        unordered_set<int> mark;
        for(auto& num: nums) mark.insert(num);
        
        int longest = 1;

        for(auto num: mark) {
            if(mark.find(num-1) == mark.end()) {
                int x = num;
                int curr = 1;
                while(mark.find(x+1) != mark.end()) {
                    curr++;
                    x++;
                }
                longest = max(longest, curr);
            }
        }
        
        return longest;
    }
};