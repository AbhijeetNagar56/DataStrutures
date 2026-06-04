class Solution {
private:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i, int j, int key, int col, vector<vector<bool>>& vis, vector<vector<int>>& img) {
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || img[i][j] != key) {
            return;
        }

        vis[i][j] = true;
        img[i][j] = col;

        for(auto& d: dir) {
            int ni=i+d[0];
            int nj=j+d[1];

            dfs(ni, nj, key, col, vis, img);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        dfs(sr, sc, image[sr][sc], color, vis, image);

        return image;
    }
};