class Solution {
private:
    vector<vector<int>> res;
    void backtrack(int i, vector<int>& subset, const vector<int>& a) {
        if(i >= a.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(a[i]);
        backtrack(i+1, subset, a);
        subset.pop_back();
        backtrack(i+1, subset, a);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(0, subset, nums);

        return res;
    }
};
