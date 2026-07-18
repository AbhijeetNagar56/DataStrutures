#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int check[26] = { 0 };
    char cf[11] = "codeforces";
    for(char c: cf) check[c-'a']++;

    int t;
    cin >> t;
    while(t--) {
        char ch;
        cin >> ch;
        if(check[ch-'a'] != 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }

        cout << "\n";
    }

    return 0;
}