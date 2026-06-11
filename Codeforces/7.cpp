// 546A
// #include <iostream>
// using namespace std;

// int main() {
// 	int k, n, w;
// 	cin >> k >> n >> w;
//     int ans = k*(w*(w+1)/2) - n;
//     if(ans < 0) ans = 0;
//     cout << ans << endl;
// 	return 0;
// }


// 118A
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
// 	string s;
// 	cin >> s;
//     string ans;
//     for(int i = 0; i < s.size(); i++) {
//         if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' ||
//             s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
//             continue;
//         }
//         ans += '.';
//         ans += tolower(s[i]);
//     }
//     cout << ans << endl;
// 	return 0;
// }

// 344A
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
// 	int n; 
// 	cin >> n;
//     int comp=0;
//     string pre = "";
//     while(n--) {
//         string m;
//         cin >> m;
//         if(pre=="") {
//             comp++;
//         } else {
//             if(pre[1] == m[0]) {
//                 comp++;
//             }
//         }
//         pre=m;
//     }
//     cout << comp << endl;

// 	return 0;
// }

// 200 B
// #include <iostream>
// #include <iomanip>
// using namespace std;
// int main() {
// 	int n;
//     double sum=0; 
// 	cin >> n;
//     int cpy=n;
//     while(n--) {
//         int p;
//         cin >> p;
//         sum+=p;
//     }
//     double avg = sum / cpy;
//     cout << fixed << setprecision(12) << avg << endl;
// 	return 0;
// }

// 61A
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
// 	string s, t, ans;
// 	cin >> s >> t;
//     for(int i=0; i<s.length(); i++) {
//         if(s[i]!=t[i]) {
//             ans+="1";
//         } else {
//             ans+="0";
//         }
//     }
//     cout << ans << endl;
// 	return 0;
// }

// 1328A
#include <iostream>
using namespace std;
int main() {
	int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a%b==0) {
            cout << "0" << endl;
            continue;
        }
        int next= b*((a+b)/b) - a;
        cout << next << endl;
    }
	return 0;
}