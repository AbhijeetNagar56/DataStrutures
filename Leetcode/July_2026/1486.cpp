class Solution {
public:
    int xorOperation(int n, int start) {
        int num = 0;

        for(int i=0; i<n; i++) {
            int curr = start + 2*i;
            num ^= curr;
        }

        return num;
    }
};