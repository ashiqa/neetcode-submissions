class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //for loop 
        //i , j -> n
        //nums[i] < nums[j]
        
        int n = nums.size(), maxRes = 1;
        vector<int>dp(n, 1);
        for (int i = n-2; i >= 0; --i){
            for (int j = i + 1; j < n; ++j){
                if (nums[i] < nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxRes = max(maxRes, dp[i]);
                }
            }
        }
        return maxRes;
    }
};
