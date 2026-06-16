// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     if(n % 2 == 0) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }
// }


// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     for(int i = 0; i < n; i++) {
//         string s;
//         cin >> s;
//         int ss = s.length();
//         if(ss <= 10) {
//             cout << s << endl;
//         } else {
//             cout << s[0] << to_string(ss - 2) << s[ss - 1] <<endl;
//         }
//     }

//     return 0;
// }

// 405A
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // bubblesort
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}