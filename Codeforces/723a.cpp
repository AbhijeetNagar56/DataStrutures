#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void meet_dist(vector<int>& a) {

    sort(a.begin(), a.end());
    int median = a[1], dist = 0;

    for(int i=0; i<3; i++) {
        dist += abs(median - a[i]);
    }

    cout << dist << "\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    
    meet_dist(a);
    return 0;
}