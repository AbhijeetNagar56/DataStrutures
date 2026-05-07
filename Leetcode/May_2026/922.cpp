class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        vector<int> res(nums.size(), 0);

        int e = 0, o = 1;

        for (int num: nums) {
            if(num % 2 == 0) {
                res[e] = num;
                e += 2;
            } else {
                res[o] = num;
                o += 2;
            }
        }
        
        return res;
    }
};