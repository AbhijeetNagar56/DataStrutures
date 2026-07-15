#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k >= 2) {
        cout << "YES" << "\n";
        return;
    }

    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i+1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}