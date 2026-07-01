class Solution {
private:
    set<vector<int>> res;
    void dfs(int i, int s, int t, vector<int>& p, vector<int>& a) {

        if(s==t) {
            res.insert(p);
            return;
        }

        if(s>t || i>=a.size()) {
            return;
        }
        
        p.push_back(a[i]);
        dfs(i+1, s+a[i], t, p, a);


        while(i<a.size()-1 && a[i] == a[i+1]) i++;

        p.pop_back();
        dfs(i+1, s, t, p, a);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<int> p;
        dfs(0, 0, t, p, c);
        return vector<vector<int>>(res.begin(), res.end());
    }
};