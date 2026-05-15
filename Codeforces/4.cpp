// 263A
// #include <iostream>
// using namespace std;

// int main() {
//     int r = -1, c = -1;

//     int n;
//     for(int i = 0; i < 5; i++) {
//         for(int j = 0; j < 5; j++) {
//             cin >> n;
//             if(n == 1) {
//                 r = i;
//                 c = j;
//             }
//         }
//     }
    
//     int row = r >= 2 ? r - 2 : 2 - r;
//     int col = c >= 2 ? c - 2 : 2 - c;

//     cout << row + col << endl;
//     return 0;
// }



// 112A
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