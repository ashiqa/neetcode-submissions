class Solution {
public:
    void bfs(queue<pair<int,int>> q, vector<vector<bool>> &ocean, vector<vector<int>>& heights){

        int r = ocean.size(), c = ocean[0].size();

        while (!q.empty()){

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            for (int k = 0; k < 4; ++k) {

                int new_x = x + dir[k][0];
                int new_y = y + dir[k][1];

                if (new_x < r && new_x >=0 && new_y <c && new_y >=0
                && !ocean[new_x][new_y]
                && heights[new_x][new_y] >= heights[x][y]) {
                    ocean[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool> > pacific(r, vector<bool>(c, false));
        vector<vector<bool> > atlantic(r, vector<bool>(c, false));
        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;

        // set boundary conditions
        for (int i = 0; i < r; ++i) {
            for (int j = 0 ; j < c; ++j){
               if (i == 0 || j == 0) {
                    pacific[i][j] = true;
                    pq.push({i,j});
               } 
               if (i == r - 1 || j == c - 1) {
                    atlantic[i][j] = true;
                    aq.push({i,j});
               } 
            }
        }

        bfs(pq, pacific, heights);
        bfs(aq, atlantic, heights);

        // store cells with flow to A and P
        vector<vector<int>> res;
        for (int i = 0; i < r; ++i) {
            for (int j = 0 ; j < c; ++j){
               if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i,j});
               } 
            }
        }
        return res;
    }
};
