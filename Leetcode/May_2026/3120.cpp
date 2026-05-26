class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<char> s;
        int visit[26] = {0};
        int ans = 0;

        for(char c: word) {
            if(c >= 'a' && c <= 'z') {
                if(s.find(toupper(c)) != s.end() && !visit[c - 'a']) {
                    ans++;
                    visit[c - 'a'] = 1;
                    s.erase(toupper(c));
                } else {
                    s.insert(c);
                }
            } else {
                if(s.find(tolower(c)) != s.end() && !visit[tolower(c) - 'a']) {
                    ans++;
                    visit[tolower(c) - 'a'] = 1;
                    s.erase(tolower(c));
                } else {
                    s.insert(c);
                }
            }
        }

        return ans;
        
    }
};