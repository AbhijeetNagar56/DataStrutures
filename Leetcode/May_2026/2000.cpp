class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> w;

        int i = 0;
        while(i < word.length() && word[i] != ch) {
            w.push(word[i]);
            i++;
        }

        if(i == word.length() && word[i - 1] != ch) return word;

        w.push(word[i]);
        i++;
        
        string ans;

        while(!w.empty()) {
            ans += w.top();
            w.pop();
        }

        while(i < word.length()) {
            ans += word[i];
            i++;
        }
        
        return ans;
    }
};