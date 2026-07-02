class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
    
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0] && dfs(i, j, 0, word, vis, board)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    int n, m;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(int i, int j, int idx, string& word, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        if(idx >= word.length()) {
            return true;
        }

        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j] != word[idx]) {
            return false;
        }

        vis[i][j] = true;

        for(auto& d: dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            if(dfs(ni, nj, idx+1, word, vis, grid)) return true;
        }

        vis[i][j] = false;

        return false;
    }
};