class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> IDeg;
        for (string w : words) {
            for (char c : w) {
                graph[c] = unordered_set<char>();
                IDeg[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() &&
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!graph[w1[j]].count(w2[j])) {
                        graph[w1[j]].insert(w2[j]);
                        IDeg[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto &[c, deg] : IDeg) {
            if (deg == 0) {
                q.push(c);
            }
        }

        string ans;
        while (!q.empty()) {
            char char_ = q.front();
            q.pop();
            ans += char_;
            for (char neighbor : graph[char_]) {
                IDeg[neighbor]--;
                if (IDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans.size() == IDeg.size() ? ans : "";
    }
};