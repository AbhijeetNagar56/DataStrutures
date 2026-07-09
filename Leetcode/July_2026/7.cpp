class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int cpy = x;

        while(cpy) {
            int d = cpy % 10;
            ans = ans*10+d;
            cpy /= 10;
        }

        if(ans > INT_MAX || ans < INT_MIN) return 0;

        return (int)ans;


    }
};
