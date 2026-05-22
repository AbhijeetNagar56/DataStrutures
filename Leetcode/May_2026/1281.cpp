class Solution {
public:
    int subtractProductAndSum(int n) {
        int cpy = n;
        int pdt = 1, sum = 0;

        while(cpy) {
            int digit = cpy % 10;
            pdt *= digit;
            sum += digit;
            cpy /= 10;
        }

        return pdt - sum;
    }
};