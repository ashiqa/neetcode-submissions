class Solution {
public:
    int dfs(int i, int amount, vector<int> & coins, vector<vector<int>> &dp) {
        if (i >= coins.size() || amount < 0){
            return 0;
        }
        if (amount == 0) {
            return 1;
        }
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int res = dfs(i + 1, amount, coins, dp);
        res += dfs(i, amount - coins[i], coins, dp);
        dp[i][amount] = res;
        return res;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp (coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, dp);
    }
};
