#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void solve(unordered_map<string, int>& m) {
    int n, t=0;
    cin >> n;
    while(n--) {
        string a;
        cin >> a;
        t += m[a];
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string, int> m;
    m["Tetrahedron"] = 4;
    m["Cube"] = 6;
    m["Octahedron"] = 8;
    m["Dodecahedron"] = 12;
    m["Icosahedron"] =  20;
    solve(m);
    return 0;
}