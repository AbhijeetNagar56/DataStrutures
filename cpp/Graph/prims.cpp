#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


void prims(int s, int v, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> mstSet(v, false);
    
    vector<int> minWeight(v, 1e9); 

    pq.push({0, s});
    minWeight[s] = 0;
    int cost = 0;
    int edgesCount = 0;

    while(!pq.empty()) {
        auto [ w, u ] = pq.top();
        pq.pop();
        if(mstSet[u]) continue;

\
        mstSet[u] = true;
        cost += w;
        edgesCount++;

        for(auto& nbr : adj[u]) {
            int weight = nbr.first;
            int neighbor = nbr.second;

            if(!mstSet[neighbor] && weight < minWeight[neighbor]) {
                minWeight[neighbor] = weight;
                pq.push({weight, neighbor});
            }
        }
    }

    cout << "Cost of MST: " << cost << endl;
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

    prims(0, 4, adj);
    return 0;
}
