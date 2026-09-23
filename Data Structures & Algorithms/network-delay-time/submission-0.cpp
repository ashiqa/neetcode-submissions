class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> minDist(n, INT_MAX);
        int maxTime = 0;

        // build a graph
        for (int i = 0; i < times.size(); ++i){
            graph[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }

        pq.push({0, k - 1});
        minDist[k-1] = 0;


        while (!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dist != minDist[node]) {
                continue;
            }

            for (int i = 0; i < graph[node].size(); ++i){
                int nextNode = graph[node][i].first;
                int nextWt = graph[node][i].second;
                if (minDist[nextNode] > nextWt + dist) {
                    minDist[nextNode] = nextWt + dist;
                    pq.push({nextWt + dist, nextNode});
                }
            }
        }
        for (int  i = 0; i < n; ++i){
            if (minDist[i] == INT_MAX) return -1;
           maxTime = max(maxTime, minDist[i]);
        }
        return maxTime;
    }
};
