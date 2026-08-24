class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int max_fruit = 0;
        unordered_map<int, int> freq_map;
        for(int right=0; right<fruits.size(); right++) {
            if(freq_map.find(fruits[right]) == freq_map.end() && freq_map.size() == 2) {
                while(freq_map.size() == 2) {
                    freq_map[fruits[left]]--;
                    if(freq_map[fruits[left]] == 0) freq_map.erase(fruits[left]);
                    left++;
                }
            }
            freq_map[fruits[right]]++;
            max_fruit = max(max_fruit, right-left+1);
        }
        return max_fruit;
    }
};