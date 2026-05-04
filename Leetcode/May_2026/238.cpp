// brute force O(n^2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++) {
            int pdt = 1;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                pdt *= nums[j];
            }
            answer[i] = pdt;
        }
        return answer;
    }
}; 

// using prefix and suffix product O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Calculate prefix products
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // Calculate suffix products and multiply with prefix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};