class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist;
            bool changed = false;
            for (const auto& f : flights) {
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                    changed = true;
                }
            }
            dist = temp;
            if (!changed) break;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};