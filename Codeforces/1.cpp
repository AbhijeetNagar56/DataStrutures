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
// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     // bubblesort
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n-1-i; j++) {
//             if(arr[j] > arr[j+1]) {
//                 int tmp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = tmp;
//             }
//         }
//     }
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }


// 469A
// #include <iostream>
// #include <unordered_set>
// using namespace std;
// int main() {
//     int n, p;
//     cin >> n;
//     cin >> p;
//     unordered_set<int> Set;
//     for(int i=0; i<2*p; i++) {
//         int a;
//         cin >> a;
//         Set.insert(a);
//     }
//     if(Set.size() == n) {
//         cout << "I become the guy.";
//     } else {
//         cout << "Oh, my keyboard!";
//     }
//     cout << endl;
//     return 0;
// }


// 144A
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> pos(n);
    int Max = 0;
    int Min = 0;

    for(int i=0; i<n; i++) {
        cin >> pos[i];
    }

    for(int i=0; i<n; i++) {
        if(pos[Max] < pos[i]) {
            Max = i;
        }

        if(pos[Min] >= pos[i]) {
            Min = i;
        }
    }
    int time = Min < Max ? -1 : 0;
    time += Max-0 + n - 1 - Min; 
    cout << time << endl;
    return 0;
}