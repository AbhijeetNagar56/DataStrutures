#include <iostream>
#include <queue>
using namespace std;

void solve() {
    priority_queue<long long> pq;
    long long sum = 0;

    for(int i=0; i<3; i++) {
        long long n;
        cin >> n;
        sum+=n;
        pq.push(n);
    }

    long long left = 0;
    bool valid = false;
    while(pq.size()>0) {
        long long n = pq.top();
        pq.pop();
        left += n;
        sum -= n;
        if(left == sum) {
            valid = true;
            break;
        }
    }
    if(valid) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}