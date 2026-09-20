class Solution {
public:
    bool searchWordRecursion(int start, string s, unordered_set<string> keywords, 
    vector<int> &dp){
        if (start >= s.length()) {
            return true;
        }

        if (dp[start] != -1){
            if (dp[start] == 0) return false;
            else return true; 
        }

        string word = "";
        for (int i = start; i < s.length(); ++i) {
            word += s[i];
            if (keywords.contains(word)){
                if(searchWordRecursion(i + 1, s, keywords, dp)) {
                    dp[start] = 1;
                    return true;
                }
            }
        }
        dp[start] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> keywords(wordDict.begin(), wordDict.end());
        vector<int>dp(n, -1);
        return searchWordRecursion(0, s, keywords, dp);
    }
};
