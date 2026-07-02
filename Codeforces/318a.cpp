#include <iostream>
using namespace std;

void get_index(long long n, long long k) {
    long long p = n % 2 == 0 ? n / 2 : n / 2 + 1;

    bool odd = true;
    if(k > p) {
        k = k - p;
        odd = false;
    }

    cout << 2*(k - 1) + (odd ? 1 : 2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    get_index(n, k);

    return 0;
}