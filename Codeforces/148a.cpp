#include <iostream>
#include <vector>
using namespace std;
int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    vector<bool> damage(d, false);

    for(int i=k-1; i<d; i+=k) {
        damage[i]=true;
    }
    for(int i=l-1; i<d; i+=l) {
        damage[i]=true;
    }
    for(int i=m-1; i<d; i+=m) {
        damage[i]=true;
    }
    for(int i=n-1; i<d; i+=n) {
        damage[i]=true;
    }
    int ct = 0;
    for(bool d: damage) {
        if(d) ct++;
    }
    cout << ct << "\n";
    return 0;
}