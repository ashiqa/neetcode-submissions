class Solution {
public:
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        int r  = grid.size(), c = grid[0].size();

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            for (int k = 0; k < 4; ++k) {
                if (x + dir[k][0] < r && x + dir[k][0] >= 0 
                && y + dir[k][1] < c && y + dir[k][1] >= 0 
                && !visited[x + dir[k][0]][y + dir[k][1]]
                && grid[x + dir[k][0]][y + dir[k][1]] == '1') {
                    q.push({x + dir[k][0], y + dir[k][1]});
                    visited[x + dir[k][0]][y + dir[k][1]] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r  = grid.size(), c = grid[0].size(), cnt = 0;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j){
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j, grid, visited);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
