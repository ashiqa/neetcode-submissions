class Solution {
public:
    bool recurse(vector<vector<char>>& board, vector<vector<bool>> &vis, string word, int i, int j, int c) { 
        if (c == word.size()){
            return true;
        }
        if (i< 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j] || word[c] != board[i][j]){
            return false;
        }
        vis[i][j] = true;
        bool res = recurse(board, vis, word, i + 1, j, c + 1) || recurse(board, vis, word, i, j + 1, c + 1) || recurse(board, vis, word, i - 1, j, c + 1)|| recurse(board, vis, word, i, j - 1, c + 1);
        vis[i][j] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        for(int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == word[0]){
                    if (recurse(board, vis, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
