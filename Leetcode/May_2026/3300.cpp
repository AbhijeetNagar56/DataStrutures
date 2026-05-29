class Solution {
private:
    int sum(int n) {
        int s = 0;
        while(n) {
            int d = n % 10;
            s += d;
            n /= 10;
        }
        return s;
    }
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int s = sum(n);
            ans = min(ans, s);
            nums[i] = s;
        }
        return ans;
    }
};