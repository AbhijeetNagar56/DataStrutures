#include <iostream>
using namespace std;

void find() {
    int n, k;
    bool pos = false;

    cin >> n >> k;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a == k) {
            pos = true;
        }
    }

    cout << (pos ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        find();
    }
    return 0;
}