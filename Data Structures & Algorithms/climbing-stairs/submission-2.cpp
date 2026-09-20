class Solution {
public:
    int recurse(int n, vector<int>&dp) {
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1){
            return dp[n];
        }
        dp[n] = recurse(n-1, dp) + recurse(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n + 1, -1);
        dp[0] = 1;
       return recurse(n, dp);
    }
};
