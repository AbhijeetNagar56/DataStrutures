class Solution {
public:
    bool isValid(string s) {
        stack<char> element;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                element.push(c);
            } else {
                if (element.empty()) return false;

                char top = element.top();
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    element.pop();
                } else {
                    return false;
                }
            }
        }

        return element.empty();
    }
};