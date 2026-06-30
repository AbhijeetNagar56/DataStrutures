class Solution {
private:
    vector<vector<int>> result;
    void dfs(int i, int curr, int target, vector<int> path, vector<int> a) {
        if(curr > target || i >= a.size()) return;

        if(curr == target) {
            result.push_back(path);
            return;
        }

        curr += a[i];
        path.push_back(a[i]);
        dfs(i, curr, target, path, a);
        curr -= a[i];
        path.pop_back();
        dfs(i+1, curr, target, path, a);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, 0, target, {}, nums);
        return result;
    }
};
