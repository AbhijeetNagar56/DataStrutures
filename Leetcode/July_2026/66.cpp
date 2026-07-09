class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        reverse(digits.begin(), digits.end());

        digits.push_back(0);
        digits[0] += 1;
        for(int i=0; i<n; i++) {
            digits[i+1] += digits[i] / 10;
            digits[i] = digits[i] % 10;
        }


        if(digits[n] == 0) digits.pop_back();

        reverse(digits.begin(), digits.end());

        return digits;
    }
};