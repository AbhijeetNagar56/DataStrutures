#include <iostream>
#include <string>
using namespace std;

bool prints(string& s) {
    for(auto& c: s) {
        if(c == 'H' || c == 'Q' || c == '9') {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string in;
    getline(cin, in);
    if(prints(in)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << "\n";
    return 0;
}