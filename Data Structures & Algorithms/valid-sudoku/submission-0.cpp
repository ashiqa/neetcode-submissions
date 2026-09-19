class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> grid(9);
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[i].size(); ++j){
               int val = board[i][j];
               if (val == '.')continue;
               if (rows[i].find(val) != rows[i].end()){
                    return false;
               } else {
                rows[i].insert(val);
               }
               if (cols[j].find(val) != cols[j].end()){
                    return false;
               } else {
                cols[j].insert(val);
               }
               int idx = 3 * floor(i/3) + floor(j/3);
               if (grid[idx].find(val) != grid[idx].end()){
                    return false;
               } else {
                grid[idx].insert(val);
               }
            }
        }
        return true;
    }
};
