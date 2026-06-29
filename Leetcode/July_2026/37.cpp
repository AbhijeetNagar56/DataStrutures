class Solution {
private:
    vector<vector<char>> result;

    bool safe(int row, int col, char num, vector<vector<char>>& board) {

        // vertical check
        for(int i=0; i<9; i++) {
            if(board[i][col] == num) return false;
        }

        // horizontal check
        for(int i=0; i<9; i++) {
            if(board[row][i] == num) return false;
        }

        // 3x3 check
        int r = (row/3) * 3;
        int c = (col/3) * 3;
        for(int i=r; i<r+3; i++) {
            for(int j=c; j<c+3; j++) {
                if(board[i][j] == num) return false;
            }
        }

        // safe
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(int n='1'; n<='9'; n++) {
                        if(safe(i, j, n, board)) {
                            board[i][j] = n;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                } 
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};