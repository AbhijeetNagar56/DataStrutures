#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
    string ans;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' ||
            s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
            continue;
        }
        ans += '.';
        ans += tolower(s[i]);
    }
    cout << ans << endl;
	return 0;
}