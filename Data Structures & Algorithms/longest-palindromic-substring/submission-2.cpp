class Solution {
public:
    int palindromeCntSubstring(int i, int j, int &maxRes, int &maxId, string &s, vector<vector<int>> &dp) {
        if (i >= j){
            return 1;
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        if (s[i] == s[j] && palindromeCntSubstring(i+1, j-1, maxRes, maxId, s, dp) == 1) {
            dp[i][j] = 1;
            int len = j - i + 1;
            if (len > maxRes){
                maxId = i;
                maxRes = len;
            }
        } else {
             dp[i][j] = 0;
            palindromeCntSubstring(i + 1, j - 1, maxRes, maxId, s, dp);
            palindromeCntSubstring(i + 1, j, maxRes, maxId, s, dp);
            palindromeCntSubstring(i, j - 1, maxRes, maxId, s, dp);
        }
        return dp[i][j];
    }

    string longestPalindrome(string s) {

        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxRes = 1, maxId = 0;
        palindromeCntSubstring(0, n-1, maxRes, maxId, s, dp);
        return s.substr(maxId, maxRes);
    }
};
