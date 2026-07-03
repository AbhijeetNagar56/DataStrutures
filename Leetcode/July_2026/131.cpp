class Solution {
private:
    vector<vector<string>> res;

    bool isPalindrome(int left, int right, string& s) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void dfs(int j, int i, string& s, vector<string>& part) {
        if(i >= s.size()) {
            if(j == i) {
                res.push_back(part);
            }
            return;
        }

        if(isPalindrome(j, i, s)) {
            part.push_back(s.substr(j, i-j+1));
            dfs(i+1, i+1, s, part);
            part.pop_back();
        }

        dfs(j, i+1, s, part);
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> part;

        dfs(0, 0, s, part);

        return res;

    }
};
