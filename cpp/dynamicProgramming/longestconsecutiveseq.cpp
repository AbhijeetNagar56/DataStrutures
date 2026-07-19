class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, bool> visited;

        for (int n: nums) visited[n] = false;

        for (int num: nums) {
            if(visited.find(num - 1) != visited.end() && !visited[num - 1]) {
                visited[num] = true;
                ans++;
            } 
            if(visited.find(num + 1) != visited.end() && !visited[num - 1]) {
                visited[num] = true;
                ans++;
            } 
        }

        return ans;

    }
};
