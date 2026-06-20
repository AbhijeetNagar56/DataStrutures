// 231A
// #include <iostream>
// using namespace std;

// int main() {
//     int n, total = 0;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         int v, curr;
//         for(int j = 0; j < 3; j++) {
//             cin >> v;
//             curr += v;
//         }
//         if(curr >= 2) {
//             total++;
//         }
//         curr = 0;
//     }
    
//     cout << total << endl;

//     return 0;
// }

// 282A
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int n, total = 0;
//     cin >> n;

//     for(int i = 0; i < n; i++) {
//         string s;
//         cin >> s;
//         if(s == "++X" || s == "X++") {
//             total++;
//         } else {
//             total--;
//         }
//     }

//     cout << to_string(total) << endl;
//     return 0;
// }

// 148A
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    vector<bool> damage(d, false);

    for(int i=k-1; i<d; i+=k) {
        damage[i]=true;
    }
    for(int i=l-1; i<d; i+=l) {
        damage[i]=true;
    }
    for(int i=m-1; i<d; i+=m) {
        damage[i]=true;
    }
    for(int i=n-1; i<d; i+=n) {
        damage[i]=true;
    }
    int ct = 0;
    for(bool d: damage) {
        if(d) ct++;
    }
    cout << ct << "\n";
    return 0;
}