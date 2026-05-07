class Solution {
public:
    int positions(vector<vector<char>> board, int r, int c) {
        int pawns = 0;
        // top
        int i = r;
        while(i >= 0) {
            if(board[i][c] == 'p') {
                pawns++;
                break;
            } else if (board[i][c] == 'B') {
                break;
            }
            i--;
        }

        // bottom
        i = r;
        while(i < board.size()) {
            if(board[i][c] == 'p') {
                pawns++;
                break;
            } else if (board[i][c] == 'B') {
                break;
            }
            i++;
        }

        // left
        i = c;
        while(i >= 0) {
            if(board[r][i] == 'p') {
                pawns++;
                break;
            } else if (board[r][i] == 'B') {
                break;
            }
            i--;
        }

        // right
        i = c;
        while(i < board[0].size()) {
            if(board[r][i] == 'p') {
                pawns++;
                break;
            } else if (board[r][i] == 'B') {
                break;
            }
            i++;
        }
        return pawns;

    }

    int numRookCaptures(vector<vector<char>>& board) {
        int a = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'R') {
                    a = positions(board, i, j);
                    break;
                }
            }
        }
        return a;
    }
};