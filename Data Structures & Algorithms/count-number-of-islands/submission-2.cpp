class Solution {
public:
    void bfs(int i, int j, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        int r  = grid.size(), c = grid[0].size();

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            for (int k = 0; k < 4; ++k) {
                int new_x = x + dir[k][0], new_y = y + dir[k][1];
                if (new_x < r && new_x >= 0 
                &&  new_y < c && new_y >= 0 
                && grid[new_x][new_y] == '1') {
                    grid[new_x][new_y] = '0';
                    q.push({new_x, new_y});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r  = grid.size(), c = grid[0].size(), cnt = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j){
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
