class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> vis;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dir = {0, 1, 0, -1, 0};

        pq.push({grid[0][0], 0, 0});
        vis.insert({0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if (r == n - 1 && c == n - 1) {
                return t;
            }
            for (int i=0; i<4; i++) {
                int nr = r + dir[i], nc = c + dir[i+1];
                if (nr < 0 || nc < 0 || nr == n ||
                    nc == n || vis.count({nr, nc})) {
                    continue;
                }
                vis.insert({nr, nc});
                pq.push({ max(t, grid[nr][nc]), nr, nc });
            }
        }

        return 0;
    }
};