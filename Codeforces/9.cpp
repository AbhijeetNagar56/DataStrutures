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
// #include <iostream>
// using namespace std;

// int main() {
//     int n, h;
//     cin >> n >> h;
//     int ans = 0;
//     for(int i=0; i<n; i++) {
// 	    int a;
// 	    cin >> a;
// 	    if(a > h) {
// 		    ans += 2;
// 	    } else {
// 		    ans++;
// 	    }
//     }
//     cout << ans << endl;
//     return 0;
// }


// 116A
// #include <iostream>
// using namespace std;

// int main() {
// 	int stops;
// 	cin >> stops;
// 	int curr = 0;
// 	int peak = 0;
// 	while(stops--) {
// 		int in, out;
// 		cin >> out >> in;
// 		curr = curr - out + in;
// 		peak = max(peak, curr);
// 	}
// 	cout << peak << endl;
// 	return 0;
// }


// 1030A
// #include <iostream>
// using namespace std;

// int main() {
// 	int n;
// 	cin >> n;
// 	bool easy = true;
// 	for(int i=0; i<n; i++) {
// 		int op;
// 		cin >> op;
// 		if(op == 1) {
// 			easy = false;
// 			break;
// 		}
// 	}

// 	if(easy) {
// 		cout << "EASY" << endl;
// 	} else {
// 		cout << "HARD" << endl;
// 	}
// 	return 0;
// }

// 266B
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;
// int main() {
// 	int n, t;
// 	cin >> n >> t;
// 	string q;
// 	q.resize(n);
// 	for(int i=0; i<n; i++) {
// 		cin >> q[i];
// 	}
// 	while(t--) {
// 		for(int i=1; i<n; i++) {
// 			if(q[i] == 'G' && q[i-1] == 'B') {
// 				swap(q[i], q[i-1]);
// 				i++;
// 			}
// 		}
// 	}
// 	cout << q << endl;
// 	return 0;
// }

// 467A
// #include <iostream>
// using namespace std;
// int main() {
// 	int n;
// 	cin >> n;
// 	int ans=0;
// 	for(int i=0; i<n; i++) {
// 		int p, q;
// 		cin >> p >> q;
// 		if(q-p>=2) {
// 			ans++;
// 		}
// 	}
// 	cout << ans << endl;
// 	return 0;
// }

// 486A
#include <iostream>
using namespace std;
int main() {
	long long n;
	cin >> n;
    long long ans;
    if(n % 2== 0) {
        ans = n/2;
    } else {
        ans = -1*(n/2) - 1;
    }
    cout << ans << endl;
	return 0;
}