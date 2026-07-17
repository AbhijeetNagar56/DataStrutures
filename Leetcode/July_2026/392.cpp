class Solution {
private:
    int m, n;
    bool rec(string& s, string& t, int i, int j) {
        if(i>=m) {
            return true;
        }
        if(j>=n) {
            return false;
        }

        if(s[i] == t[j]) {
            return rec(s, t, i+1, j+1);
        } else {
            return rec(s, t, i, j+1);
        }
    }

public:
    bool isSubsequence(string s, string t) {
        m = s.length();
        n = t.length();

        return rec(s, t, 0, 0);

    }
};