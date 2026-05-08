class Solution {
public:
    bool isAN(char c) {
        if((c >= '0' && c <= '9') || (tolower(c) >= 'a' && tolower(c) <= 'z')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while(l < r) {
            if(!isAN(s[l])) {
                l++;
                continue;
            }
            if(!isAN(s[r])) {
                r--;
                continue;
            }

            if(tolower(s[r]) != tolower(s[l])) return false;

            l++;
            r--;
        }

        return true;
    }
};