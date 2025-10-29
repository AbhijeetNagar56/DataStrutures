package Algorithms;

public class sudoku {
    public static boolean isSafe(char[][] board, int row, int col, int number) {
        // column
        for(int i = 0; i < board.length; i++) {
            if(board[i][col] == (char)(number + '0')) {
                return false;
            }
        }

        // row
        for(int j = 0; j < board.length; j++) {
            if(board[row][j] == (char)(number + '0')) {
                return false;
            }
        }

        // grid

        int sr = 3 * (row/3);
        int sc = 3 * (col/3);

        for(int i = sr; i < sr + 3; i++) {
            for(int j = sc; j < sc + 3; j++) {
                if(board[i][j] == (char)(number + '0')) {
                    return false;
                }
            }
        }

        return true;
    }
    public static boolean helper(char[][] board, int row, int col) {
        if(row == board.length){
            return true;
        }
        int nrow = 0;
        int ncol = 0;
        if(col != board.length - 1) {
            nrow = row + 1;
            ncol = 0;
        } else {
            nrow = row;
            ncol = col + 1;
        }
        if(board[row][col] != '.') {
            if(helper(board, nrow, ncol)) {
                return true;
            }
        } else {
            for(int i = 1; i <=9; i++) {
                if(isSafe(board, row, col, i)) {
                    board[row][col] = (char)(i+'0');
                    if(helper(board, nrow, ncol)) {
                        return true;
                    } else {
                        board[row][col] = '.';
                    }
                }
            }
        }
        
        return false;
    }
    public static void solveSudoku(char[][] board) {
        helper(board, 0, 0);
    }
    public static void main(String[] args) {
        System.out.println();
        char[][] sudoku = {
            {'5','3','4','6','7','8','9','1','2'},
            {'6','7','2','1','9','5','3','4','8'},
            {'1','9','8','3','4','2','5','6','7'},
            {'8','5','9','7','6','1','4','2','3'},
            {'4','2','6','8','5','3','7','9','1'},
            {'7','1','3','9','2','4','8','5','6'},
            {'9','6','1','5','3','7','2','8','4'},
            {'2','8','7','4','1','9','6','3','5'},
            {'3','4','5','2','8','6','1','7','9'}
        };

        solveSudoku(sudoku);

        for(int i = 0; i < sudoku.length; i++) {
            System.out.print("| ");
            for(int j = 0; j < sudoku.length; j++) {
                System.out.print(sudoku[i][j] + " | ");
            }
            System.out.println();
        }

    }
}
