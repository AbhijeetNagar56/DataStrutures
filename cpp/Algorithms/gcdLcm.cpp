#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b==0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a/gcd(a, b))*b;
}


int main() {

    long long a, b;
    cout << "Enter space separeted a b ? \n";
    cin >> a >> b;

    cout << "GCD of a and b is " << gcd(a, b) << "\n";
    cout << "LCM of a and b is " << lcm(a, b) << "\n";

    return 0;
}