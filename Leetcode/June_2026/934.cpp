class Solution {
private:
    int n;
    const vector<vector<int>> nbr = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& g, queue<pair<int,int>>& q) {
        if(x < 0 || y < 0 || x >= n || y >= n || vis[x] [y] || g[x] [y] == 0) {
            return;
        }
        vis[x] [y] = true;
        q.push({x, y});

        for(auto& dir : nbr) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            dfs(nx, ny, vis, g, q);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        bool found = false;

        for(int i = 0; i < n; ++i) {
            if(found) break;
            for(int j = 0; j < n; ++j) {
                if(grid[i] [j] == 1) {
                    dfs(i, j, vis, grid, q);
                    found = true;
                    break;
                }
            }
        }

        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                for(auto& dir : nbr) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx] [ny]) {
                        if(grid[nx] [ny] == 1) {
                            return dist; 
                        }
                        vis[nx] [ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};