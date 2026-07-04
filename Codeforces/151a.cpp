#include <iostream>
using namespace std;

void solve(int n, int k, int l, int c, int d, int p, int nl, int np) {
    int total_drink = k*l;
    int total_slice = c*d;

    int drink_round = total_drink / (n*nl);
    int slice_round = total_slice / n;
    int salt_round = p / (np*n);



    cout << min(drink_round, min(slice_round, salt_round)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    solve(n, k, l, c, d, p, nl, np);
    return 0;
}