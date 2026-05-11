class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, water = 0, level = 0;

        // while(l < r && height[l] == 0) l++;
        // while(r > l && height[r] == 0) r--;

        while(l < r) {
            int h = min(height[l], height[r]);
            if(h > level) {
                water += (h - level) * (r - l - 1);
                level = h;
            }

            if(height[l] < height[r]) {
                l++;
                water -= min(level, height[l]);
            } else {
                r--;
                water -= min(level, height[r]);
            }
        }

        return water;
    }
};