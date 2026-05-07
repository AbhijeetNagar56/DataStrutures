class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1;

        for(int num: nums1) n1[num]++;

        vector<int> ans;


        for(int num: nums2) {
            if(n1.find(num) != n1.end() && n1[num] != 0) {
                ans.push_back(num);
                n1[num]--;
            }
        }



        return ans;
    }
};