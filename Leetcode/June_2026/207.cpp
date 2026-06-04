class Solution {
private:
    bool isCycle(int src, vector<bool>& vis, vector<bool>& rec, vector<vector<int>>& edges) {
        vis[src] = true;
        rec[src] = true;

        for(int i=0; i<edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src) {
                if(!vis[v]){
                    if(isCycle(v, vis, rec, edges)) {
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

public:
    bool canFinish(int n, vector<vector<int>>& edges) {
         vector<bool> vis(n, false);
         vector<bool> rec(n, false);


         for(int i=0; i<n; i++) {
            if(!vis[n]) {
                if(isCycle(i, vis, rec, edges)) {
                    return false;
                }
            }
         }

         return true;
    }
};