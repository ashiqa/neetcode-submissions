class Solution {
public:
    void recurse(int i, vector<int> nums, vector<bool> &visited,
    vector<int> &permSet, vector<vector<int>> &res) {
        if (permSet.size() == nums.size()){
            res.push_back(permSet);
            return;
        }
        for (int i = 0; i < visited.size(); ++i) {
            if (visited[i] == false) {
                visited[i] = true;
                permSet.push_back(nums[i]);
                recurse(i, nums, visited, permSet, res);
                permSet.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> permSet; 
        int n = nums.size();
        vector<bool>visited(n, false);
        recurse(0, nums, visited, permSet, res);
        return res;
    }

};
