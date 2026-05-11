class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        sort(arr2.begin(), arr2.end());

        for (int n1: arr1) {
            if(isValid(n1, arr2, d)) {
                ans++;
            }
        }

        return ans;
    }
    
    bool isValid(int n, vector<int>& arr2, int d) {
        int l = 0;
        int r = arr2.size() - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;

            if(abs(arr2[m] - n) <= d) {
                return false;
            } else if(arr2[m] < n) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return true;
    }
};