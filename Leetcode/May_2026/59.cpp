class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        int i = 1;
        int r = 0;
        int c = 0;
        int dir = 0; // 0: right, 1: bottom, 2: left, 3: top
        int dr[] = {0, 1, 0, -1}; // Direction changes for rows
        int dc[] = {1, 0, -1, 0}; // Direction changes for columns

        while (i <= n * n) {
            res[r] [c] = i++;
            
            // Calculate next position
            int nextR = r + dr[dir];
            int nextC = c + dc[dir];

            // Check if next position is out of bounds or already filled
            if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n || res[nextR] [nextC] != -1) {
                // Change direction clockwise
                dir = (dir + 1) % 4;
                nextR = r + dr[dir];
                nextC = c + dc[dir];
            }

            r = nextR;
            c = nextC;
        }
        return res;
    }
};