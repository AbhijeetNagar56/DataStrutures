class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> curr;


        dfs(0, curr, nums);

        return vector<vector<int>>(res.begin(), res.end());

    }
private:
    int n;
    set<vector<int>> res;
    void dfs(int i, vector<int>& c, vector<int>& a) {
        if(i >= a.size()) {
            // sort(c.begin(), c.end());
            res.insert(c);
            return;
        }


        c.push_back(a[i]);
        dfs(i+1, c, a);

        c.pop_back();
        dfs(i+1, c, a);
    }
};
