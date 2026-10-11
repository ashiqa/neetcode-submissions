class Solution {
public:
    bool dfs(int idx, int parent, vector<vector<int>> &graphs, set<int>&vis) {
        bool res = true;
        for (int i = 0; i < graphs[idx].size(); ++i) {
            int nextNode = graphs[idx][i];
            if (nextNode == parent)continue;
            if (vis.contains(nextNode))return false;
            vis.insert(nextNode);
            res = res && dfs(nextNode, idx, graphs, vis);
        } 
        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graphs(n);
        for (auto e: edges) {
            graphs[e[0]].push_back(e[1]);
            graphs[e[1]].push_back(e[0]);
        }
        set<int> vis;
        vis.insert(0);
        bool res = dfs(0, -1, graphs, vis);

        if (vis.size() != n)return false;
        return res;
    }
};
