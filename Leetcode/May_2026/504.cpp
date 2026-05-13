class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        bool pos = true;
        if(num == 0) return "0";
        if(num < 0) pos = false;
        num = abs(num);

        while(num) {
            int bit = num % 7;
            ans = to_string(bit) + ans;
            num /= 7;
        }

        if(!pos) ans = "-" + ans;
        return ans;

    }
};