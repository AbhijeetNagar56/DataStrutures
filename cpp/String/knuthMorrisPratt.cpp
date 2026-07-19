#include <bits/stdc++.h>
using namespace std;

// Build LPS (Longest Prefix Suffix) array
vector<int> buildLPS(const string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix
    for (int i = 1; i < m; ) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

// KMP search
vector<int> KMPsearch(const string& text, const string& pat) {
    int n = text.size(), m = pat.size();
    vector<int> lps = buildLPS(pat);
    vector<int> matches;
    int i = 0, j = 0; // i for text, j for pattern

    while (i < n) {
        if (text[i] == pat[j]) {
            i++; j++;
            if (j == m) {
                matches.push_back(i - j); // match found
                j = lps[j - 1];           // continue search
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matches;
}

int main() {
    string text = "ababcabcabababd";
    string pat = "ababd";
    vector<int> result = KMPsearch(text, pat);

    for (int idx : result) {
        cout << "Pattern found at index " << idx << endl;
    }
    return 0;
}
