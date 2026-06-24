#include <iostream>
#include <vector>
using namespace std;


long long recursion(long long n) {
    if(n == 0 || n == 1) return n;
    return recursion(n-1) + recursion(n-2);
}


long long memo(long long n, vector<long long>& cache) {
    if(cache[n]) return cache[n];

    if(n == 0 || n == 1) return n;

    cache[n-1] = memo(n-1, cache);
    cache[n-2] = memo(n-2, cache);

    return cache[n-1] + cache[n-2];
}

long long tabu(long long n) {
    if(n == 0 || n == 1) return n;
    vector<long long> dp(n+1, 0);
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


int main() {
    long long n;
    cin >> n;

    vector<long long> cache(n+1, 0);

    cout << "Recursion: " << recursion(n) << endl;
    // cout << "Memoization: " << memo(n, cache) << endl;
    // cout << "Tabulation: " << tabu(n) << endl;

    return 0;
}