class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<vector<int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                    vis[i][j] = true;
                }
            }
        }

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int t = q.front()[2];
            q.pop();

            ans = max(ans, t);

            for(auto d: dir) {
                int nx = x+d[0];
                int ny = y+d[1];

                if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] || grid[nx][ny] != 1) {
                    continue;
                }

                q.push({ nx, ny, t + 1 });
                vis[nx][ny] = true;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return ans;

    }
}; 