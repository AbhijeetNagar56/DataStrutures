class Solution {
private:
    vector<vector<int>> subset;
    void dfs(vector<bool>& vis, vector<int>& c, vector<int>& a) {
        if(c.size()==a.size()) {
            subset.push_back(c);
            return;
        }
        
        for(int i=0; i<a.size(); i++) {
            if(!vis[i]) {
                vis[i] = true;
                c.push_back(a[i]);
                dfs(vis, c, a);
                c.pop_back();
                vis[i] = false;
            }
        }

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> c;
        vector<bool> v(nums.size(), false);
        dfs(v, c, nums);
        return subset;
        
    }
};
