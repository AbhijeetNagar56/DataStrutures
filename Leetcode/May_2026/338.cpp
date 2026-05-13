class Solution {
public:
    vector<int> countBits(int n) {
        // even to odd 1 increase
        vector<int> ans(n+1);


        for (int i = 0; i <= n; i++) {
            int n = i;
            while(n) {
                ans[i] += n % 2;
                n /= 2;
            }
        }

        return ans;
    }
};