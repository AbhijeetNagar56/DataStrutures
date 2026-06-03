class Solution {
private:
    int currArea;
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid, int m, int n) {
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j] == 0) {
            return;
        }

        vis[i][j] = true;
        currArea++;
        dfs(i, j - 1, vis, grid, m, n); // left
        dfs(i, j + 1, vis, grid, m, n); // right
        dfs(i - 1, j, vis, grid, m, n); // top
        dfs(i + 1, j, vis, grid, m, n); // bottom
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int maxArea = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    currArea = 0;
                    dfs(i, j, vis, grid, m, n);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;
    }
};