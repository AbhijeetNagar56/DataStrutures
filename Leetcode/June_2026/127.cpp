class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            pair<string, int> curr = q.front();
            q.pop();
            string currentWord = curr.first;
            int currentLen = curr.second;

            if (currentWord == endWord) {
                return currentLen;
            }

            string originalWord = currentWord;
            for (int i = 0; i < currentWord.length(); ++i) {
                char originalChar = currentWord[i];

                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue;

                    currentWord[i] = c;

                    if (wordSet.find(currentWord) != wordSet.end() && visited.find(currentWord) == visited.end()) {
                        visited.insert(currentWord);
                        q.push({currentWord, currentLen + 1});
                    }
                }
                
                currentWord[i] = originalChar;
            }
        }

        return 0;
    }
};