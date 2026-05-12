class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> rank;
        int i = 0;
        for(vector<int> r: mat) {
            int st = 0;
            for(int s: r) {
                if(s == 0) break;
                st++;
            }
            rank.push_back({st ,i});
            i++;
        }

        sort(rank.begin(), rank.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || a[1] < b[1];
        });

        vector<int> ans;
        i = 0;
        while(i < k) {
            ans.push_back(rank[i][1]);
            i++;
        }

        return ans;
    }
};