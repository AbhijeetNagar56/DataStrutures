#include <iostream>
using namespace std;


long long pow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while(b) {
        if(b & 1) {
            res = (res*a) % mod;
        }
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}


int main() {
    const int mod = 1e10;
    long long a, b;
    cout << "Enter space separeted a b ? \n";
    cin >> a >> b;

    cout << pow(a, b, mod) << "\n";

    return 0;
}