class Solution {
public:
    void recurse(vector<int>& nums, int i, vector<int> &subset, int target, vector<vector<int>> &res){
        if (i >= nums.size() || target < 0){
            return;
        }

        if (target == 0) {
            res.push_back(subset);
            return;
        }

        recurse(nums, i + 1, subset, target, res);
        subset.push_back(nums[i]);
        recurse(nums, i, subset, target - nums[i], res);
        subset.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        vector<int> subset;
        recurse(nums, 0, subset, target, res);

        return res;
    }
};
