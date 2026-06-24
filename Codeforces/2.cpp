// 231A
// #include <iostream>
// using namespace std;

// int main() {
//     int n, total = 0;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         int v, curr;
//         for(int j = 0; j < 3; j++) {
//             cin >> v;
//             curr += v;
//         }
//         if(curr >= 2) {
//             total++;
//         }
//         curr = 0;
//     }
    
//     cout << total << endl;

//     return 0;
// }

// 282A
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int n, total = 0;
//     cin >> n;

//     for(int i = 0; i < n; i++) {
//         string s;
//         cin >> s;
//         if(s == "++X" || s == "X++") {
//             total++;
//         } else {
//             total--;
//         }
//     }

//     cout << to_string(total) << endl;
//     return 0;
// }

// 148A
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int k, l, m, n, d;
//     cin >> k >> l >> m >> n >> d;
//     vector<bool> damage(d, false);

//     for(int i=k-1; i<d; i+=k) {
//         damage[i]=true;
//     }
//     for(int i=l-1; i<d; i+=l) {
//         damage[i]=true;
//     }
//     for(int i=m-1; i<d; i+=m) {
//         damage[i]=true;
//     }
//     for(int i=n-1; i<d; i+=n) {
//         damage[i]=true;
//     }
//     int ct = 0;
//     for(bool d: damage) {
//         if(d) ct++;
//     }
//     cout << ct << "\n";
//     return 0;
// }


// 443A
// #include <iostream>
// #include <string>
// #include <sstream>
// #include <unordered_set>
// using namespace std;
// int main() {
//     string s;
//     getline(cin, s);
//     unordered_set<int> Set;
//     stringstream input(s);
//     int i=0;
//     while(i<s.length()) {
//         char ch;
//         input >> ch;
//         if(ch >= 'a' && ch <='z') {
//             Set.insert(ch);
//         }
//         i++;
//     }
//     cout << Set.size() << "\n";
//     return 0;
// }

// 479A
// #include <iostream>
// using namespace std;

// int main() {
//     long long a, b, c;
//     cin >> a >> b >> c;
//     long long largest=0;
//     if(a+b+c>largest) {
//         largest = a+b+c;
//     }
//     if(a*b*c > largest) {
//         largest = a*b*c;
//     }
//     if((a+b)*c > largest) {
//         largest = (a+b)*c;
//     }
//     if(a*(b+c)>largest) {
//         largest = a*(b+c);
//     }
//     if(a*b+c>largest) {
//         largest = a*b+c;
//     }
//     if(a+b*c>largest) {
//         largest = a+b*c;
//     }
//     cout << largest << "\n";
//     return 0;
// }

// 1742A
// #include <iostream>
// #include <queue>
// using namespace std;

// void solve() {
//     priority_queue<long long> pq;
//     long long sum = 0;

//     for(int i=0; i<3; i++) {
//         long long n;
//         cin >> n;
//         sum+=n;
//         pq.push(n);
//     }

//     long long left = 0;
//     bool valid = false;
//     while(pq.size()>0) {
//         long long n = pq.top();
//         pq.pop();
//         left += n;
//         sum -= n;
//         if(left == sum) {
//             valid = true;
//             break;
//         }
//     }
//     if(valid) {
//         cout << "YES";
//     } else {
//         cout << "NO";
//     }
//     cout << "\n";
// }

// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         solve();
//     }
//     return 0;
// }

//510A 
#include <iostream>
using namespace std;
void draw(int n, int m) {
    bool isRight = true;
    for(int i=0; i<n; i++) {
        if(i % 2 != 0) {
            if(!isRight) {
                cout << "#";
            } else {
                cout << ".";
            }
            for(int j=0; j<m-2; j++) {
                cout << ".";
            }
            if(isRight) {
                cout << "#";
            } else {
                cout << ".";
            }

            isRight = !isRight;
        } else {
            for(int j=0; j<m; j++) {
                cout << "#";
            }
        }
        cout << "\n";
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    draw(n, m);
    return 0;
}