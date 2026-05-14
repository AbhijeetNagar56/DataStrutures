class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> merge(m + n);

        int i = 0, j = 0, k = 0;

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                merge[k++] = nums1[i++];
            } else {
                merge[k++] = nums2[j++];
            }
        }

        while(i < m) {
            merge[k++] = nums1[i++];
        }

        while(j < n) {
            merge[k++] = nums2[j++];
        }

        if((m + n) % 2 == 1) return (double)(merge[(m + n) / 2]);

        double med = (double)(merge[(m + n) / 2] + merge[(m + n - 2) / 2]) / 2;

        return med;
    }
};