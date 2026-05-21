// 281 A

// #include <iostream>
// #include <string>
// using namespace std;

// int main () {
//     string s;
//     cin >> s;
//     if(s[0] >= 'a' && s[0] <= 'z') {
//         s[0] = s[0] - ('a' - 'A');
//     }
//     cout << s << endl;
//     return 0;
// }

// 791 A
#include <iostream>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;

    int t = 0;
    while(a <= b) {
        a *= 3;
        b *= 2;
        t++;
    }
    cout << t << endl;
    return 0;
}