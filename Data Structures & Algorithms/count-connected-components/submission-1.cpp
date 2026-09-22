class Solution {
public:

    int find(int curr, vector<int> &parent){
        while (parent[curr] != curr){
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }
    int _union(int u, int v, vector<int> &parent, vector<int> &rank){
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu == pv){
            return 0;
        } else {
            if (rank[pu] > rank[pv]){
                parent[pv] = pu;
                rank[pu] += rank[pv];
            } else {
                parent[pu] = pv;
                rank[pv] += rank[pu];
            }
            return 1;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        vector<int>rank(n, 1);

        for (int i = 0; i < n; ++i){
            parent[i] = i;
        }
        int res = n;
        for (int i = 0; i < edges.size(); ++i){
            res -= _union(edges[i][0], edges[i][1], parent, rank);
        }
        return res;
    }
};
