class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1]; 
            int time = edge[2]; 
            
            adj[u].push_back({time, v});
        }

        vector<int> dist(n + 1, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int time = edge.first;
                int v = edge.second;

                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    pq.push({dist[v], v});
                }
            }
        }

        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};