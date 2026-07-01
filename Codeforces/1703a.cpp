#include <iostream>
using namespace std;

bool valid(char* s) {
    char g[3] = {'y', 'e', 's'};
    for(int i=0; i<3; i++) {
        if(tolower(s[i]) != g[i]) return false;
    }
    return true;
}
int main (){
    int t;
    cin >> t;
    while(t--) {
        char s[3];
        for(int i=0; i<3; i++) {
            cin >> s[i];
        }
        if(valid(s)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
}