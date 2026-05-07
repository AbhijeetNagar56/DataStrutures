class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int total_sa = 0;
        int rows = grid.size();
        int cols = grid.size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i] [j] == 0) continue;

                // Add top and bottom + 4 sides
                total_sa += 4 * grid[i] [j] + 2;

                // Subtract overlaps with neighbors (only check right and down to avoid double counting)
                if (j + 1 < cols) {
                    total_sa -= 2 * min(grid[i] [j], grid[i] [j + 1]);
                }
                if (i + 1 < rows) {
                    total_sa -= 2 * min(grid[i] [j], grid[i + 1] [j]);
                }
            }
        }

        return total_sa;
    }
};