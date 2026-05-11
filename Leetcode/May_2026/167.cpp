// two pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        vector<int> ans;

        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum < target) {
                l++;
            } else if(sum > target) {
                r--;
            } else {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                break;
            }
        }

        return ans;
    }
};


// hash map

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        unordered_map<int, int> index;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int compliment = target - numbers[i];
            if(index.find(compliment) != index.end()) {
                ans.push_back(index[compliment] + 1);
                ans.push_back(i + 1);
                break;
            }

            index[numbers[i]] = i;
        }

        

        return ans;
    }
};