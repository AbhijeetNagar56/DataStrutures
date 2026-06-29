#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, vector<bool>& used) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        // Choose
        path.push_back(nums[i]);
        used[i] = true;

        // Explore
        backtrack(nums, path, result, used);

        // Unchoose
        path.pop_back();
        used[i] = false;
    }
}

int main() {
    
    return 0;
}
