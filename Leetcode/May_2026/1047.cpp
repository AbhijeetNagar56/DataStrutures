class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        string ans;

        for(char ch: s) {
            if(!stk.empty() && stk.top() == ch) {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }

        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};