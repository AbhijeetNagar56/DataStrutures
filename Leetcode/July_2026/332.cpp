class Solution {
private:
    unordered_map<string, multiset<string>> adj;
    vector<string> res;

    void dfs(string src) {
        while (!adj[src].empty()) {
            string nbr = *adj[src].begin();
            adj[src].erase(adj[src].begin());
            dfs(nbr);
        }

        res.push_back(src);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (const auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }


        dfs("JFK");


        reverse(res.begin(), res.end());
        return res;
    }
};
