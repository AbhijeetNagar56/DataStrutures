class Solution {
public:
    int findComplement(int num) {
        long pow = 1;
        long ans = 0;

        while(num) {
            if(num % 2 == 0) {
                ans += 1 * pow;
            } else {
                ans += 0 * pow;
            }

            pow *= 2;
            num /= 2;
        }

        return (int)ans;
    }
};