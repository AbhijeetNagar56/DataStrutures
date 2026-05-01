class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();

        if(r*c != m*n) return mat;
        vector<vector<int>> result(r, vector<int>(c, 0));

        int row = 0, col =0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[row][col] = mat[i][j];
                if(col == c - 1) {
                    row++;
                    col = 0;
                } else {
                    col++;
                }
            }
        }

        return result;
    }
};