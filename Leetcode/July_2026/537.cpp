class Solution {
private:
    // a, b
    pair<int, int> getNum(string num) {
        int plus;
        for(int i=0; i<num.size(); i++) {
            if(num[i] == '+') {
                plus = i;
                break;
            }
        }

        int x, y;
        string a = num.substr(0, plus);
        string b = num.substr(plus + 1, num.size()-2);
        if(a[0] == '-') {
            x = -1 * stoi(a.substr(1, a.size()-1));
        } else {
            x = stoi(a);
        }

        if(b[0] == '-') {
            y = -1 * stoi(b.substr(1, b.size()-1));
        } else {
            y = stoi(b);
        }

        return { x, y };
    }

    string convert(int a, int b) {
        return to_string(a) + "+" + to_string(b) + "i";
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> n1 = getNum(num1);
        pair<int, int> n2 = getNum(num2);

        int res_real = n1.first * n2.first - n1.second * n2.second;
        int res_img = n1.second*n2.first + n2.second*n1.first;

        return convert(res_real, res_img);
    }
};