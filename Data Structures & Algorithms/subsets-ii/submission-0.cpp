class Solution {
public:
    void recurse(vector<int> nums, int i, vector<int> &subset, vector<vector<int>> &res) {
        if (i > nums.size()){
            return;
        }
        if (i == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        recurse(nums, i + 1, subset, res);
        subset.pop_back();

        while (i + 1< nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        recurse(nums, i + 1, subset, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        recurse(nums, 0, subset, res);
        return res;
    }
};
