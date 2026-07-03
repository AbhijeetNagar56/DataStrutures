
class Solution {
private:
    vector<string> res;
    unordered_map<char, string> MP;

    void fill() {
        MP['2'] = "abc";
        MP['3'] = "def";
        MP['4'] = "ghi";
        MP['5'] = "jkl";
        MP['6'] = "mno";
        MP['7'] = "pqrs";
        MP['8'] = "tuv";
        MP['9'] = "wxyz";
    }

    void dfs(int i, string curr, int s, const string& n) {
        if (i >= s) {
            res.push_back(curr);
            return;
        }

        string letters = MP[n[i]];
        
        for (char ch : letters) {
            dfs(i + 1, curr + ch, s, n);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        fill();
        dfs(0, "", digits.length(), digits);

        return res;
    }
};