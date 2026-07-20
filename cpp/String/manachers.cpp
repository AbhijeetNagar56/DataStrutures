string longestPalindrome(string s) {
    // Transform string: add separators (#) to handle even-length palindromes
    string t = "@";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";

    int n = t.size();
    vector<int> P(n, 0);
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2*center - i;
        if (i < right)
            P[i] = min(right - i, P[mirror]);

        while (t[i + 1 + P[i]] == t[i - 1 - P[i]])
            P[i]++;

        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    // Find max length
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}
