#include <iostream>
using namespace std;

void test() {
    int n;
    cin >> n;

    int odds = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(a & 1 == 1) {
            odds++;
        }
    }

    cout << (odds % 2 == 0 ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        test();
    }
    return 0;
}