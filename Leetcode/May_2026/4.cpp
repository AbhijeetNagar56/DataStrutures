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


// space optimal
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int s = m + n;
        int medianIdx = s / 2;
        
        int last = -1, curr = -1;
        int i = 0, j = 0;
        
        for (int k = 0; k <= medianIdx; k++) {
            last = curr;
            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
        }
        
        if (s % 2 == 0) {
            return (last + curr) / 2.0;
        } else {
            return curr;
        }
    }
};