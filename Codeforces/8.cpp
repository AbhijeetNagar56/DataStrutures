// 59A
// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <cctype>
// using namespace std;

// int main () {
// 	string s;
// 	cin >> s;
// 	int up = 0;
// 	for(char c: s) {
// 		if(c >= 'a' && c <= 'z') {
// 			up++;
// 		} else {
// 			up--;
// 		}
// 	}
// 	if(up < 0) {
// 		transform(s.begin(), s.end(), s.begin(), ::toupper);
// 		cout << s << endl;
// 	} else {
// 		transform(s.begin(), s.end(), s.begin(), ::tolower);
// 		cout << s << endl;
// 	}
// 	return 0;
// }


// 977A
#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	while(k) {
		if(n % 10 == 0) {
			n /= 10;
		} else {
			n -= 1;
		}
		k--;
	}
	cout << n << endl;
	return 0;
}

