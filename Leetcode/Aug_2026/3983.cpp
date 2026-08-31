class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        if(m > n) return false;
        int i=0, j=0, k=0;
        while(j<m && k<n) {
            if(s[j] == t[k]) {
                j++;
            }
            j = max(j, i+1);
            if(s[i] == t[k]) {
                i++;
            }
            k++;
        }
        return j==m;
    }
};