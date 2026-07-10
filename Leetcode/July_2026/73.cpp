class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(row[i] || col[j]) {
                    a[i][j] = 0;
                }
            }
        }
    }
};
