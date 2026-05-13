class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size(), rem = n % (2 * k), i = 0;

        for(; i < n - rem; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + i + k);
        }

        int rev = (n - i >= k) ? k : n - i;

        reverse(s.begin()+ i, s.begin() + i + rev);
        
        return s;
    }
};