#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, total = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "++X" || s == "X++") {
            total++;
        } else {
            total--;
        }
    }

    cout << to_string(total) << endl;
    return 0;
}