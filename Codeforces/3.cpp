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
#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    long long ans = (n * m) / 2;

    cout << ans << endl;

    return 0;
}