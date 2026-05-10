class Solution {
public:
    bool isSame(int f[], int w[]) {
        for (int i = 0; i < 26; i++) {
            if(f[i] != w[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {


        int freq[26] = {0};

        for (char ch: s1) {
            freq[ch - 'a']++;
        }

        int windSize = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            int windIdx = 0, idx = i;
            int windFreq[26] = {0};
            while(windIdx < windSize && idx < s2.length()) {
                windFreq[s2[idx] - 'a']++;
                windIdx++; idx++;
            }
            
            if(isSame(freq, windFreq)) {
                return true;
            }
        }

        return false;
    }
};