// 41A
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main() {
//     string s, t;
//     cin >> s >> t;
//     reverse(t.begin(), t.end());
//     if(s == t) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }
//     return 0;
// }

// 271A
// #include <iostream>
// #include <climits>
// using namespace std;
// bool isValid(int n) {
//     int v[10] = {0};
//     while(n) {
//         int d = n % 10;
//         if(v[d] != 0) return false;
//         v[d] = 1;
//         n/=10;
//     }
//     return true;
// }
// int main() {
//     int n;
//     cin >> n;
//     for(int i=n+1; i<INT_MAX; i++) {
//         if(isValid(i)) {
//             cout << i << endl;
//             break;
//         }
//     }
//     return 0;
// }


// 677A
#include <iostream>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int ans = 0;
    for(int i=0; i<n; i++) {
	    int a;
	    cin >> a;
	    if(a > h) {
		    ans += 2;
	    } else {
		    ans++;
	    }
    }
    cout << ans << endl;
    return 0;
}
