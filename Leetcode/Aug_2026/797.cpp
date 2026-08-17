class Solution {
private:
    vector<vector<int>> paths;

    void dfs(int src, int dst, vector<int>& curr, vector<vector<int>>& graph, vector<bool>& vis) {
        if(vis[src]) {
            return;
        }


        vis[src] = true;
        curr.push_back(src);


        if(src == dst) {
            paths.push_back(curr);
        } else {
            for(auto& nbr: graph[src]) {
                dfs(nbr, dst, curr, graph , vis);
            }
        }
        
        curr.pop_back();
        vis[src] = false;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);

        vector<int> curr;

        dfs(0, n-1, curr, graph, vis);

        return paths;
    }
};