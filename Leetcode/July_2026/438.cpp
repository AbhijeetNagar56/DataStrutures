class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<int> ans;

        if (n > m) return ans;

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

        for (int i = 0; i < n; i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        if (pCount == sCount) {
            ans.push_back(0);
        }

        for (int i = n; i < m; i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - n] - 'a']--;

            if (pCount == sCount) {
                ans.push_back(i - n + 1);
            }
        }

        return ans;
    }
};