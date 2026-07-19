#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long l = (n + a - 1) / a;
    long long b = (m + a - 1) / a;

    long long ans = l * b;

    cout << ans << endl;

    return 0;
}