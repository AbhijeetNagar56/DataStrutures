#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t seed = 0;
            for (int i : v) {
                seed ^= hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

private:
    int m, n;

    bool dfs(int i, int j, string& s, string& p, unordered_map<vector<int>, bool, VectorHash>& cache) {

        if (cache.find({i, j}) != cache.end()) {
            return cache[{i, j}];
        }

        if (j >= n) {
            return i >= m;
        }

        bool match = i < m && (s[i] == p[j] || p[j] == '.');

        if (j < n - 1 && p[j + 1] == '*') {
            cache[{i, j}] = dfs(i, j + 2, s, p, cache) || (match && dfs(i + 1, j, s, p, cache));
            return cache[{i, j}];
        }

        if (match) {
            cache[{i, j}] = dfs(i + 1, j + 1, s, p, cache);
            return cache[{i, j}];
        }

        cache[{i, j}] = false;
        return false;
    }

public:
    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();
        unordered_map<vector<int>, bool, VectorHash> cache;
        return dfs(0, 0, s, p, cache);
    }
};