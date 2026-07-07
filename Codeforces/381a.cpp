#include <iostream>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int deque[n];

    for(int i=0; i<n; i++) {
        cin >> deque[i];
    }

    int l=0;
    int r=n-1;

    int sereja = 0, dima = 0;
    bool serejaTurn = true;

    while(l<=r) {
        int max_num;
        if(deque[l] < deque[r]) {
            max_num = deque[r--];
        } else {
            max_num = deque[l++];
        }

        if(serejaTurn) {
            sereja += max_num;
        } else {
            dima += max_num;
        }

        serejaTurn = !serejaTurn;
    }

    cout << sereja << " " << dima << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}