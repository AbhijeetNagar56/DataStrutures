class Twitter {
    int time;
    unordered_map<int, vector<vector<int>>> tm;
    unordered_map<int, set<int>> fm;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tm[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);

        fm[userId].insert(userId);
        for (int followeeId : fm[userId]) {
            if (tm.count(followeeId)) {
                const vector<vector<int>>& tweets = tm[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        while (!minHeap.empty() && res.size() < 10) {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if (index > 0) {
                const vector<int>& tweet = tm[curr[2]][index - 1];
                minHeap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        fm[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        fm[followerId].erase(followeeId);
    }
};