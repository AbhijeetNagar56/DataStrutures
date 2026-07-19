#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long largest=0;
    if(a+b+c>largest) {
        largest = a+b+c;
    }
    if(a*b*c > largest) {
        largest = a*b*c;
    }
    if((a+b)*c > largest) {
        largest = (a+b)*c;
    }
    if(a*(b+c)>largest) {
        largest = a*(b+c);
    }
    if(a*b+c>largest) {
        largest = a*b+c;
    }
    if(a+b*c>largest) {
        largest = a+b*c;
    }
    cout << largest << "\n";
    return 0;
}