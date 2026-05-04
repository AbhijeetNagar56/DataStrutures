class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0, digits = 0;

        int copy = n; // copy to iterate

        // finding length
        while (copy > 0) {
            digits++;
            copy /= 10;
        }

        copy = n;

        // finding reverse number
        while (copy > 0) {
            rev += (copy % 10) * pow(10, --digits);
            copy /= 10;
        }

        return abs(n - rev);

    }
};