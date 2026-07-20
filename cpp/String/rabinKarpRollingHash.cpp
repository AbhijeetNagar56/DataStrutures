#include <bits/stdc++.h>
using namespace std;

const int d = 256; // number of characters in input alphabet

vector<int> rabinKarp(string text, string pattern, int q) {
    int n = text.size();
    int m = pattern.size();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text window
    int h = 1;
    vector<int> matches;

    // h = pow(d, m-1) % q
    for (int i = 0; i < m-1; i++)
        h = (h * d) % q;

    // Initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            if (text.substr(i, m) == pattern)
                matches.push_back(i);
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
    return matches;
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    int prime = 101; // modulus for hashing

    vector<int> result = rabinKarp(text, pattern, prime);
    for (int idx : result) {
        cout << "Pattern found at index " << idx << endl;
    }
    return 0;
}
