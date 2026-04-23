// Brute Force Solution
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);

        for (int i = 0; i < n; i++) {
            int key = nums[i];
            for (int j = 0; j < n; j++) {
                if(i == j) continue;
                if(nums[j] == key) arr[i] += abs(i - j);
            }
        }

        return arr;


    }
};


// Optimized Solution using Hash Map
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> Map;

        for (int i = 0; i < n; i++) {
            Map[nums[i]].push_back(i);
        }

        vector<long long> arr(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto &idx : Map[nums[i]]) {
                if(idx == i) continue;
                arr[i] += abs(idx - i);
            }
        }

        return arr;

    }
};

// Optimized Solution using Hash Map and Prefix Sum
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> Map;

        for (int i = 0; i < n; i++) {
            Map[nums[i]].push_back(i);
        }

        vector<long long> arr(n, 0);

        for(auto &it : Map){
            auto &pos = it.second;

            long long sum = 0;
            for(int x : pos) sum += x;

            long long leftSum = 0;
            int m = pos.size();

            for(int i = 0; i < m; i++){
                long long rightSum = sum - leftSum - pos[i];

                long long left  = 1LL * pos[i] * i - leftSum;
                long long right = rightSum - 1LL * pos[i] * (m-i-1);

                arr[pos[i]] = left + right;

                leftSum += pos[i];
            }
        }

        return arr;

    }
};