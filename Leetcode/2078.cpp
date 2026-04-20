class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0, right = colors.size() - 1;

        while (left < right) {
            if(colors[left] != colors[right]) return right - left;

            int l = left, r = right;
            while(l < colors.size() && colors[l] == colors[right]) l++;
            while(r >=0 && colors[r] == colors[left]) r--;

            // calculation of left steps and right steps

            l - left < right - r ? left = l : right = r;

        }

        return 0;
    }
};


// Optimized Solution
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int left = 0, right = n - 1, l = left, r = right;

        while(l < n && colors[l] == colors[right]) l++;
        while(r >=0 && colors[r] == colors[left]) r--;

        // calculation of left steps and right steps
        l - left < right - r ? left = l : right = r;

        return right - left;
    }
};