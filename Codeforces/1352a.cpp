#include <iostream>
#include <vector>
using namespace std;
void solve() {
    long long num;
    cin >> num;
    int div = 10;
    vector<int> sums;
    while(num / div) {
        int a = num % div;
        if(a != 0) sums.push_back(a);
        num = (num / div) * div;
        div *= 10;
    }
    sums.push_back(num % div);
    cout << sums.size() << "\n";
    for(int i=sums.size() - 1; i>=0; i--) {
        cout << sums[i] << " ";
    }
    cout << "\n";
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