class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> res(n1 + n2, 0);

        for(int i=0; i<n1; i++) {
            for(int j=0; j<n2; j++) {
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';
                int prod = d1*d2;
                res[i+j] += prod;
                res[i+j+1] += res[i+j] / 10;
                res[i+j] = res[i+j] % 10;
            }
        }

        int last = n1+n2-1;
        while(last > 0 && res[last] == 0) {
            last--;
        }

        string ans = "";

        for(int i=last; i>=0; i--) {
            ans += to_string(res[i]);
        }
        
        return ans;
    }
};