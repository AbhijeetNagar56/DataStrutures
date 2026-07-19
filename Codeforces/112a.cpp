#include <iostream>
#include <string>
using namespace std;

int main() {

    string first, second;

    cin >> first;
    cin >> second;

    for (char &c : first) {
        c = tolower(static_cast<unsigned char>(c));
    }

    for (char &c : second) {
        c = tolower(static_cast<unsigned char>(c));
    }

    if(first == second) {
        cout << 0 << endl;
    } else if(first > second) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}