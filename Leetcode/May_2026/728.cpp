class Solution {
public:
    bool isValid(int num) {
        int cpy = num;
        while(num) {
            int digit = num % 10;
            if(digit == 0 || cpy % digit != 0) return false;
            num /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;

        for(int i = left; i <= right; i++) {
            if(isValid(i)) res.push_back(i);
        }

        return res;
    }
};