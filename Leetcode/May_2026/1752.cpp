class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();
        bool pivotDone = false;

        for(int i = 1; i < n; i++) {
            if(a[i] < a[i - 1] && !pivotDone) {
                pivotDone = true;
                continue;
            }

            if(a[i] < a[i - 1]) {
                return false;
            }
        }

        if(pivotDone && a[0] < a[n - 1]) return false;
        return true;
    }
};