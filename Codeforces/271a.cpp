#include <iostream>
#include <climits>
using namespace std;
bool isValid(int n) {
    int v[10] = {0};
    while(n) {
        int d = n % 10;
        if(v[d] != 0) return false;
        v[d] = 1;
        n/=10;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for(int i=n+1; i<INT_MAX; i++) {
        if(isValid(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
