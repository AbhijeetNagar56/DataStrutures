#include <iostream>
using namespace std;

void solve() {
    int a, ans = 0;
    cin >> a;
    for(int i=0; i<3; i++) {
        int p;
        cin >> p;
        if(p>a) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}