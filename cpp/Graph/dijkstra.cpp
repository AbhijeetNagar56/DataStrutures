#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;


void dijktra(int src, int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    dist[src]=0;

    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while(!pq.empty()) {
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();

        if(dist[u] < d) continue;
        for(auto& edge: adj[u]) {
            int v=edge.second;
            int w=edge.first;

            if(dist[u] + w < dist[v]) {
                dist[v]=dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }


    for(int i=0; i<dist.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

}

int main() {
    int n=4;
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 1});
    adj[1].push_back({1, 0});
    adj[1].push_back({1, 2});
    adj[2].push_back({1, 1});
    adj[2].push_back({1, 3});
    adj[3].push_back({1, 2});

    dijktra(1, 4, adj);
    return 0;
}