class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int temp = 0, idx = -1, n = size(words);

        while (temp < n) {
            if (words[temp] == target) {
                if (idx == -1) {
                    idx =
                        min(abs(startIndex - temp), abs(n + startIndex - temp));
                } else {
                    idx = min(idx, min(abs(startIndex - temp),
                                       abs(n + startIndex - temp)));
                }
            }
            temp++;
        }

        return idx;
    }
};


// corrected

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = -1;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {

                int d = abs(startIndex - i);

                int circularDist = min(d, n - d);
                
                if (minDistance == -1 || circularDist < minDistance) {
                    minDistance = circularDist;
                }
            }
        }

        return minDistance;
    }
};