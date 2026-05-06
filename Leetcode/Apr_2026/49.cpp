class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> Index; // Maps sorted string to index in ans
        
        for (const string& s : strs) {
            string s_sorted = s;
            sort(s_sorted.begin(), s_sorted.end());
            
            if (Index.find(s_sorted) == Index.end()) {
                // New group: create a new vector and add it to ans
                ans.push_back({s});
                // Store the index of this new vector
                Index[s_sorted] = ans.size() - 1;
            } else {
                // Existing group: push to the vector at the stored index
                ans[Index[s_sorted]].push_back(s);
            }
        }
        
        return ans;
    }
};