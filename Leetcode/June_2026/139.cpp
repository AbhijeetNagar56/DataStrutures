class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);

        dp[n] = true;

        for(int i=n; i>=0; i--) {
            for(auto& w: wordDict) {
                if(i+w.size() <= s.size() && s.substr(i, w.size()) == w) {
                    dp[i] = dp[i+w.size()];
                }

                if(dp[i]) {
                    break;
                }
            }
        }

        return dp[0];
    }
};