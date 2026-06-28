// // 158A
// #include <iostream>
// using namespace std;

// int main() {
//     int n, k, adv = 0;
//     cin >> n;
//     cin >> k;

//     for(int i = 0; i < n; i++) {
//         int score;
//         cin >> score;
//         if(score > k) adv++;
//     }

//     cout << adv << endl;
//     return 0;

// }


// 1A
// #include <iostream>
// using namespace std;

// int main() {
//     long long n, m, a;
//     cin >> n >> m >> a;

//     long long l = (n + a - 1) / a;
//     long long b = (m + a - 1) / a;

//     long long ans = l * b;

//     cout << ans << endl;

//     return 0;
// }


// 50A
// #include <iostream>
// using namespace std;

// int main() {
//     long long n, m;
//     cin >> n >> m;

//     long long ans = (n * m) / 2;

//     cout << ans << endl;

//     return 0;
// }


// 133A
// #include <iostream>
// #include <string>
// using namespace std;

// bool prints(string& s) {
//     for(auto& c: s) {
//         if(c == 'H' || c == 'Q' || c == '9') {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     string in;
//     getline(cin, in);
//     if(prints(in)) {
//         cout << "YES";
//     } else {
//         cout << "NO";
//     }
//     cout << "\n";
//     return 0;
// }


// 1352A
#include <iostream>
#include <vector>
using namespace std;
void solve() {
    long long num;
    cin >> num;
    int div = 10;
    vector<int> sums;
    while(num / div) {
        int a = num % div;
        if(a != 0) sums.push_back(a);
        num = (num / div) * div;
        div *= 10;
    }
    sums.push_back(num % div);
    cout << sums.size() << "\n";
    for(int i=sums.size() - 1; i>=0; i--) {
        cout << sums[i] << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}