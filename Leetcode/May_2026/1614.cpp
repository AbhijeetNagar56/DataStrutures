class Solution {
public:
    int maxDepth(string s) {
        stack<char> depth;
        int max_depth = 0;

        for(char ch: s) {
            if(ch == ')' && !depth.empty() && depth.top() == '(') {
                depth.pop();
            } else if(ch == '(') {
                depth.push(ch);
            } else {
                continue;
            }
            if(max_depth < depth.size()) max_depth = depth.size();
        }

        return max_depth;
    }
};