#include <iostream>
using namespace std;

void solve(int k, int r) {
    int ans = 0;
    for(int a=1; a<10; a++) {
        if(k*a % 10 == 0 || k*a % 10 == r) {
            ans = a;
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, r;
    cin >> k >> r;
    solve(k, r);
    return 0;
}