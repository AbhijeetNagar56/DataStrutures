#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long amt;
    cin >> amt;
    long long ans=0;
    while(amt) {
        if(amt>=100) {
            ans += amt/100;
            amt = amt - 100*(amt/100);
        } else if(amt>=20) {
            ans += amt/20;
            amt = amt - 20*(amt/20);
        } else if(amt>=10) {
            ans += amt/10;
            amt = amt - 10*(amt/10);
        } else if(amt>=5) {
            ans += amt/5;
            amt = amt - 5*(amt/5);
        } else {
            ans += amt;
            amt = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}