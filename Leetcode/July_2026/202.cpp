class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int copy = n;

        while(copy!=1) {
            if(s.find(copy) != s.end()) return false;

            s.insert(copy);
            int sum=0;

            while(copy) {
                int d= copy % 10;
                sum+=d*d;
                copy/=10;
            }

            copy=sum;
        }

        return true;
        
    }
};