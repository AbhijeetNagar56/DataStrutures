class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        int unique = 1;
        int key = candyType[0];

        for(int i = 0; i < candyType.size(); i++) {
            if(key != candyType[i]) {
                unique++;
                key = candyType[i];
            }
        }

        return unique < candyType.size() / 2 ? unique : candyType.size() / 2;
    }
};