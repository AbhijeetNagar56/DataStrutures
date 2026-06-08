class Solution {
private:
    int n;
    void dfs(int i, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[i] = true;

        for(int j=0; j<n; j++) {
            if(adj[i][j] == 1 && !vis[j]) {
                dfs(j, vis, adj);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        n=adj.size();

        vector<bool> vis(n, false);

        int comp =0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
                comp++;
            }
        }
        return comp;
    }
};