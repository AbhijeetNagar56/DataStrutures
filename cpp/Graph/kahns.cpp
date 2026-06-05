#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

void kahn(int v, unordered_map<int, unordered_set<int>>& g) {
    vector<int> inDegree(v, 0);
    for(auto& v: g) {
        for(int u: v.second) {
            inDegree[u]++;
        }
    }

    queue<int> q;
    vector<int> ans;
    for(int i=0; i<v; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto& nbr: g[curr]) {
            inDegree[nbr]--;
            if(inDegree[nbr] == 0) {
                q.push(nbr);
            }
        }
        ans.push_back(curr);
    }

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


}

int main() {
    unordered_map<int, unordered_set<int>> g;
    g[4].insert(0);
    g[4].insert(1);
    g[5].insert(0);
    g[5].insert(2);
    g[0] = {};
    g[2].insert(3);
    g[3].insert(1);
    g[1] = {};


    kahn(6, g);
    cout << "kahn's algorithm completed." << endl;
    return 0;
}