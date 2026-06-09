class Solution {
private:
    int manDist(vector<vector<int>>& points, int p1, int p2){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        unordered_set<int> mstSet;
        int mstCost=0;

        pq.push({0,0});

        while(!pq.empty()) {
            int w=pq.top().first;
            int u=pq.top().second;
            pq.pop();

            if(mstSet.find(u) != mstSet.end()) continue;
            mstSet.insert(u);
            mstCost+=w;
            for(int i=0; i<n; i++) {
                if(mstSet.find(i) == mstSet.end()) {
                    int edgeWt = manDist(points, u, i);
                    pq.push({ edgeWt, i });
                }
            }
        }

        return mstCost;
    }
};