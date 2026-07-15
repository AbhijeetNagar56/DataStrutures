class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int count : count) {
            if (count > 0) {
                pq.push(count);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (!pq.empty() || !q.empty()) {
            time++;

            if (pq.empty()) {
                time = q.front().second;
            } else {
                int count = pq.top() - 1;
                pq.pop();
                if (count > 0) {
                    q.push({count, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};