class Solution {
public:
    int find(int u, vector<int>&parent) {
        while(parent[u] != u) {
            u = parent[u];
        }
        return u;
    }
    void _union(int u, int v, vector<int>&parent, vector<int>&rank, vector<int>&res) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu == pv) {
            res = {u, v};
            return;
        }
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
            rank[pu] += rank[pv];
        } else {
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n + 1);
        vector<int>rank(n + 1);
        vector<int>res;
        for(int i = 1; i <= n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
        for(auto e: edges) {
            _union(e[0], e[1], parent, rank, res);
        }
        return res;
    }
};
