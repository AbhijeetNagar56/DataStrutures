#include <iostream> 
using namespace std;

int sum(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n/=10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cout << sum(n) << "\n";
    }

    return 0;
}