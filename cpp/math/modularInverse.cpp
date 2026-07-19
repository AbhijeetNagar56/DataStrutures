#include <iostream>
using namespace std;


long long gcdExtended(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = gcdExtended(a, m, x, y);
    if (g != 1) {
        throw runtime_error("Inverse doesn't exist");
    } else {
        return (x % m + m) % m;
    }
}


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
    // only when a, m are coprime
    const int mod = 1e10;
    long long a, m;
    cout << "Enter space separeted a m ? \n";
    cin >> a >> m;

    // method 1
    cout << modInverse(a, m) << "\n";
    
    // method 2 (when m is prime)
    // cout << pow(a, m-2, m);

    return 0;
}