class Solution {
private:
    stack<int> stk;
    bool dfs(int src, vector<bool>& vis, vector<bool>& rec, vector<vector<int>>& edges) {
        vis[src] = true;
        rec[src] = true;

        for(int i=0; i<edges.size(); i++) {
            int u=edges[i][1];
            int v=edges[i][0];

            if(src==u) {
                if(!vis[v]) {
                    if(dfs(v, vis, rec, edges)) {
                        return true;
                    }
                } else if(rec[v]) {
                    return true;
                }
            }
        }

        rec[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool>& vis, vector<vector<int>>& edges) {
        vis[src]=true;

        for(int i=0; i<edges.size(); i++) {
            int v=edges[i][0];
            int u=edges[i][1];

            if(src==u) {
                if(!vis[v]) {
                    topoSort(v, vis, edges);
                }
            }
        }

        stk.push(src);
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> rec(n, false);
        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, rec, edges)) {
                    return ans;
                }
            }
        }

        // topological sort

        vis.assign(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                topoSort(i, vis, edges);
            }
        }

        while(stk.size() > 0) {
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};