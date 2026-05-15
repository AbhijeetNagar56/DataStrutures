class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int i = 0; i < m; i++) {
            int p = 0;
            for (int j = 0; j < n; j++) {
                if(boxGrid[i][j] == '.') {
                    swap(boxGrid[i][j], boxGrid[i][p]);
                    p++;
                } else if(boxGrid[i][j] == '*') {
                    p = j + 1;
                }
            }
        }


        vector<vector<char>> rotated(n, vector<char>(m, '.'));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                rotated[j][m - 1 - i] = boxGrid[i][j];
            }
        } 


        return rotated;

        
    }
};