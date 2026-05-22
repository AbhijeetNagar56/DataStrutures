class Solution {
public:
    int maximum69Number (int num) {
        stack<int> stk;
        while(num) {
            stk.push(num % 10);
            num /= 10;
        }

        bool ch = false;
        int ans = 0;
        while(!stk.empty()) {

            if(stk.top() == 6 && !ch) {
                ans = ans*10 + 9;
                ch = true;
                stk.pop();
            } else {
                ans = ans*10 + stk.top();
                stk.pop();
            }
        }
        return ans;
    }
};