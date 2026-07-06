class Solution {
private:
    vector<int> dir = {0, 1, 0, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        int x = 0;
        int y = 0;
        int d = 0;

        while(ans.size() < m*n) {
            
            ans.push_back(matrix[x][y]);
            if(d == 0 && (y == m-1 || matrix[x][y+1] == 101)) {
                d = 1;
            } else if(d == 1 && (x == n-1 || matrix[x+1][y] == 101)) {
                d = 2;
            } else if(d == 2 && (y == 0 || matrix[x][y-1] == 101)) {
                d = 3;
            } else if(d == 3 && (x == 0 || matrix[x-1][y] == 101)) {
                d = 0;
            }

            matrix[x][y] = 101;
            
            x += dir[d];
            y += dir[d+1];
            
        }

        return ans;

    }
};
