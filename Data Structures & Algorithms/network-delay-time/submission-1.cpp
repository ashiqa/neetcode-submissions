class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>minDist(n, INT_MAX);

        for (auto t: times) {
            graph[t[0]-1].push_back({t[1]-1, t[2]});
        }
        minDist[k-1] = 0;
        pq.push({0, k-1});
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (dist != minDist[node])continue;
            for (int i = 0; i < graph[node].size(); ++i) {
                int nextNode = graph[node][i].first;
                int edgeWt = graph[node][i].second;
                if (minDist[nextNode] > dist + edgeWt) {
                    minDist[nextNode] = dist + edgeWt;
                    pq.push({minDist[nextNode], nextNode});
                }
            }
        }
        int res = 0;
        for (auto d: minDist){
            if (d == INT_MAX)return -1;
            res = max(res, d);
        }
        return res;
    }
};
