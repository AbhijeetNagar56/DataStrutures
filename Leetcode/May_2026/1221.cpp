class Solution {
public:
    int balancedStringSplit(string s) {
        int split = 0;

        int b = 0;

        for(char c: s) {
            if(c == 'R') b++;
            if(c == 'L') b--;

            if(b == 0) {
                split++;
                b = 0;
            }
        }

        return split;
    }
};