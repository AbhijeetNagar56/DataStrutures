#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int dist = -1;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == target) {
                if(dist == -1) {
                    dist = abs(start - i);
                } else {
                    dist = min(dist, abs(start - i));
                }
            }
        }
        
        return dist;
    }
};


int main () {

    return 0;
}