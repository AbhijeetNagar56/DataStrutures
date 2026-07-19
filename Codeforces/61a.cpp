#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t, ans;
	cin >> s >> t;
    for(int i=0; i<s.length(); i++) {
        if(s[i]!=t[i]) {
            ans+="1";
        } else {
            ans+="0";
        }
    }
    cout << ans << endl;
	return 0;
}