#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(nums, path, result, used);
    return result;
}

int main() {
    
    return 0;
}