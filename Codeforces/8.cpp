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
// #include <iostream>
// using namespace std;

// int main() {
// 	int n, k;
// 	cin >> n >> k;
// 	while(k) {
// 		if(n % 10 == 0) {
// 			n /= 10;
// 		} else {
// 			n -= 1;
// 		}
// 		k--;
// 	}
// 	cout << n << endl;
// 	return 0;
// }

// 69A
// #include <iostream>
// #include <vector>
// using namespace std;

// int main () {
// 	int n;
// 	cin >> n;
// 	vector<vector<int>> forces(n, vector<int>(3, 0));
// 	for(int i=0; i<n; i++) {
// 		int x, y, z;
// 		cin >> x >> y >> z;
// 		forces[i] = { x, y, z };
// 	}
// 	vector<int> fnet(3,0);
// 	for(vector<int> f: forces) {
// 		fnet[0] += f[0];
// 		fnet[1] += f[1];
// 		fnet[2] += f[2];
// 	}

// 	if(fnet[0] == 0 && fnet[1] == 0 && fnet[2] == 0) {
// 		cout << "YES" << endl;
// 	} else {
// 		cout << "NO" << endl;
// 	}

// 	return 0;
// }

// 110A
// #include <iostream>
// #include <vector>
// using namespace std;

// bool isNearlyLucky(long int n) {
// 	bool isLucky = true;
// 	int noOfLuckyDigits = 0;
// 	while(n) {
// 		long int digit = n % 10;
// 		if(digit != 4 && digit != 7) {
// 			isLucky = false;
// 		} else {
// 			noOfLuckyDigits++;
// 		}
// 		n /= 10;
// 	}

// 	bool nearlyLucky = true;
// 	while(noOfLuckyDigits) {
// 		long int digit = noOfLuckyDigits % 10;
// 		if(digit != 4 && digit != 7) {
// 			nearlyLucky = false;
// 			break;
// 		}
// 		noOfLuckyDigits /= 10;
// 	}
// 	return isLucky || nearlyLucky;
// }
// int main () {
// 	long int n;
// 	cin >> n;
// 	if(isNearlyLucky(n)) {
// 		cout << "YES" << endl;
// 	} else {
// 		cout << "NO" << endl;
// 	}
// 	return 0;
// }

// 96A
// #include <iostream>
// #include <string>
// using namespace std;

// bool isSafe(string& s) {
// 	int freq = 0;
// 	int key = 0;
// 	for(int i = 0; i < s.length(); i++) {
// 		if(s[i] == s[key]) {
// 			freq++;
// 		} else if(freq >= 7) {
// 			return false;
// 		} else {
// 			key = i;
// 			freq = 1;
// 		}
// 	}
// 	if(freq >= 7) {
// 		return false;
// 	}
// 	return true;
// }
// int main () {
// 	string s;
// 	cin >> s;
// 	if(!isSafe(s)) {
// 		cout << "YES" << endl;
// 	} else {
// 		cout << "NO" << endl;
// 	}
// 	return 0;
// }


// 734A
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	char s[n];
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}

	int a = 0, d = 0;
	for(int i=0; i<n; i++) {
		if(s[i] == 'A') {
			a++;
		} else {
			d++;
		}
	}

	if(a > d) {
		cout << "Anton" << endl;
	} else if(d > a) {
		cout << "Danik" << endl;
	} else {
		cout << "Friendship" << endl;
	}
	return 0;
}