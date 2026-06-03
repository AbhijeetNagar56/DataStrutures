class Solution {
private:
    int m, n;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(int i, int j, vector<vector<int>> arr, vector<vector<bool>>& vis) {
        vis[i][j] = true;

        for(auto& d: dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni<0 || ni>=m || nj<0 || nj>=n || vis[ni][nj] || arr[i][j] > arr[ni][nj]) continue;
            dfs(ni, nj, arr, vis);

        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        m = a.size();
        n = a[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int j=0; j<n; j++) dfs(0, j, a, pacific);
        for(int i=0; i<m; i++) dfs(i, 0, a, pacific);

        for(int j=0; j<n; j++) dfs(m-1, j, a, atlantic);
        for(int i=0; i<m; i++) dfs(i, n-1, a, atlantic);

        vector<vector<int>> ans;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({ i, j });
                }
            }
        }

        return ans;
    }
};

