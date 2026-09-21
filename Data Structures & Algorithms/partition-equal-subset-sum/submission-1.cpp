class Solution {
public:
    bool subsetSum(int id, int target, vector<int> &nums,
    vector<vector<int>> &dp){
        if (target == 0) {
            return true;
        }

        if (id >= nums.size() || target < 0){
            return false;
        }

        if (dp[id][target] != -1) {
            return dp[id][target];
        }

        dp[id][target] = subsetSum(id + 1, target - nums[id], nums, dp)
        || subsetSum(id + 1, target, nums, dp);
        return dp[id][target];
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); ++i) {
            target += nums[i];
        }
        if (target % 2 == 1){
            return false;
        }
        vector<vector<int>>dp (nums.size(), vector<int>(target + 1, -1));
        return subsetSum(0, target/2 , nums, dp);
    }
};
