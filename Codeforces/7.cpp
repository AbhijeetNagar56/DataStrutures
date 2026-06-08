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
#include <iostream>
#include <string>
using namespace std;
int main() {
	int n; 
	cin >> n;
    int comp=0;
    string pre = "";
    while(n--) {
        string m;
        cin >> m;
        if(pre=="") {
            comp++;
        } else {
            if(pre[1] == m[0]) {
                comp++;
            }
        }
        pre=m;
    }
    cout << comp << endl;

	return 0;
}