class Solution {
private:
    int expandFromCenter(int l, int r, int n, string& s) {
        int count = 0;
        while(l>=0 && r<n && s[l]==s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int total = 0;

        for(int i=0; i<n; i++) {
            // even length
            int even = expandFromCenter(i, i+1, n, s);
            // odd length
            int odd = expandFromCenter(i, i, n, s);

            total += even + odd;
        }

        return total;
    }
};