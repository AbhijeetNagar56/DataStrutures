#include <iostream>
using namespace std;

void solve(int n, int k) {
    int min = 240 - k;

    int solved = 0;
    
    while(min >= 0) {
        solved++;
        min -= solved *5;
    }

    solved--;
    int ans = n < solved ? n : solved;

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}