class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;

        int n = x ^ y;
        while(n) {
            ans += n % 2;
            n/= 2;
        }

        return ans;
    }
};