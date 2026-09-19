class Solution {
public:
    void recurse(vector<int>& nums, int i, vector<int> subset, vector<vector<int>> &res) {
        if (i >= nums.size()){
            res.push_back(subset);
            return;
        } 
        recurse(nums, i + 1, subset, res);
        subset.push_back(nums[i]);
        recurse(nums, i + 1, subset, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset; 
        recurse(nums, 0, subset, res);
        return res;
    }
};
