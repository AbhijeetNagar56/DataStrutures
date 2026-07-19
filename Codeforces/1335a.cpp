#include <iostream>
using namespace std;
long long perm(long long n) {
    long long ans;
    if(n % 2 == 0) {
        ans = n / 2 - 1;
    } else {
        ans = n / 2;
    }

    return ans;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long result = perm(n);
        cout << result << "\n";
    }
    return 0;
}