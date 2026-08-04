#include <iostream>
#include <unordered_map>
using namespace std;

void solve() {
    unordered_map<int, pair<int, int>> mp;
    int n; 
    cin >> n;
    int i=1;
    while(n--) {
        int a;
        cin >> a;
        mp[a].first++;
        mp[a].second =  i;
        i++;
    }

    for(auto& p: mp) {
        if(p.second.first == 1) {
            cout << p.second.second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}