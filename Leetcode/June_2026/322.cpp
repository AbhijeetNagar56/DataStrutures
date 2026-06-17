// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int coin = 0;

//         sort(coins.begin(), coins.end(), [](int a, int b) { return a > b; });

//         int c=0;

//         while(amount) {
//             if(amount >= coins[c]) {
//                 amount -= coins[c];
//                 coin++;
//             } else {
//                 if(c<coins.size()-1) {
//                     c++;
//                 } else {
//                     return -1;
//                 }
//             }
//         }


//         return coin;
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& arr, int amt) {
        vector<int> dp(amt+1, amt+1);
        dp[0] = 0;

        for(int i=1; i<=amt; i++) {
            for(int j=0; j<arr.size(); j++) {
                if(arr[j] <= i) {
                    dp[i] = min(dp[i], dp[i-arr[j]] + 1);
                }
            }
        }

        return dp[amt] > amt ? -1 : dp[amt];
    }
};

