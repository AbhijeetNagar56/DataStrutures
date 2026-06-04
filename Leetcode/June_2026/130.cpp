class Solution {
private:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || board[i][j] == 'X') {
            return;
        }

        vis[i][j] = true;

        for(auto& d: dir) {
            dfs(i+d[0], j+d[1], board, vis);
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));


        for(int j=0; j<n; j++) {
            if(board[0][j] == 'O') {
                dfs(0, j, board, vis);
            }
        }
        for(int j=0; j<n; j++) {
            if(board[m-1][j] == 'O') {
                dfs(m-1, j, board, vis);
            }
        }
        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0, board, vis);
            }
        }
        for(int i=0; i<m; i++) {
            if(board[i][n-1] == 'O') {
                dfs(i, n-1, board, vis);
            }
        }


        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O' && vis[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};