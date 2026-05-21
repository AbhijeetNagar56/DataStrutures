class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sstk;
        stack<char> tstk;

        for(char c: s) {
            if(!sstk.empty() && c == '#') {
                sstk.pop();
            } else if (c == '#') {
                continue;
            } else {
                sstk.push(c);
            }
        }

        for(char c: t) {
            if(!tstk.empty() && c == '#') {
                tstk.pop();
            } else if (c == '#'){
                continue;
            } else {
                tstk.push(c);
            }
        }

        return sstk == tstk;
    }
};