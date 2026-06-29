#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;

    bool safe(int r, int c, const vector<string>& board, int n) {
        // horizontal
        for (int j = 0; j < n; j++) {
            if (board[r] [j] == 'Q') return false;
        }

        // diagonals
        
        int i = r, j = c;
        
        // Up-Right
        while (i >= 0 && j < n) {
            if (board[i] [j] == 'Q') return false;
            i--;
            j++;
        }

        // Down-Right
        i = r; j = c;
        while (i < n && j < n) {
            if (board[i] [j] == 'Q') return false;
            i++;
            j++;
        }

        
        return true;
    }

    void back(int col, vector<string>& board, int n) {

        if (col < 0) {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (safe(row, col, board, n)) {
                board[row] [col] = 'Q';
                back(col - 1, board, n);
                board[row] [col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        
        back(n - 1, board, n);
        
        return result;
    }
};