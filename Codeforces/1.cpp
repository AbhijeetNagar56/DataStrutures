#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int ss = s.length();
        if(ss <= 10) {
            cout << s << endl;
        } else {
            cout << s[0] << to_string(ss - 2) << s[ss - 1] <<endl;
        }
    }

    return 0;
}