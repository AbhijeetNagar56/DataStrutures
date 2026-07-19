#include <iostream>
#include <string>
using namespace std;

bool isSafe(string& s) {
	int freq = 0;
	int key = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == s[key]) {
			freq++;
		} else if(freq >= 7) {
			return false;
		} else {
			key = i;
			freq = 1;
		}
	}
	if(freq >= 7) {
		return false;
	}
	return true;
}
int main () {
	string s;
	cin >> s;
	if(!isSafe(s)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}