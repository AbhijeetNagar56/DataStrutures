#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int>& h, vector<int>& a) {
    int count = 0;

    for(int i=0; i<n; i++) {
        int home = h[i];

        for(int j=0; j<n; j++) {
            if(i==j) continue;
            if(a[j] == home) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> h(n, 0);
    vector<int> a(n, 0);
    int i=0;
    while(i<n) {
        cin >> h[i] >> a[i];
        i++;
    }
    cout << solve(n, h, a) << "\n";
    return 0;
}