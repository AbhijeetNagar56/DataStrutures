// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int n = nums.size();
//         if(n < 3) return 0;

//         sort(nums.begin(), nums.end());

//         long long ans = INT_MAX;

//         for (int i = 0; i < n - 1; i++) {
//             if(i >0 && nums[i] == nums[i - 1]) continue;
//             int left = i + 1;
//             int right = n - 1;

//             double curr;

//             while(left < right) {
//                 curr = nums[i] + nums[left] + nums[right];

//                 if(curr > target) {
//                     right--;
//                 } else if(curr < target) {
//                     left++;
//                 } else {
//                     return curr;
//                 }
//             }


//             if(abs(curr - target) < abs(ans - target)) {
//                 ans = curr;
//             }
//         }

//         return static_cast<int>(ans);
//     }
// };
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i++){

            if(i>0 and nums[i]==nums[i-1])
                continue;

            int j=i+1;
            int k=n-1;

            while(j<k){

                int sum = nums[i]+nums[j]+nums[k];

                if(sum==target){
                    return target;
                }

                else if(sum<target){

                    maxi=max(maxi,sum);
                    j++;
                }

                else{

                    mini=min(mini,sum);
                    k--;
                }
            }
        }

        if(maxi==INT_MIN)
            return mini;

        if(mini==INT_MAX)
            return maxi;

        int first=abs(target-mini);
        int second=abs(target-maxi);

        if(first<=second)
            return mini;

        return maxi;
    }
};