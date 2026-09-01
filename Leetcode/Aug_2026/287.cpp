class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num: nums) {
            if(seen.find(num) != seen.end()) {
                return num;
            }
            seen.insert(num);
        }

        return -1;
    }
};

// O(1) space optimized two pointer approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        int slow2 = nums[0];
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;        
    }
};