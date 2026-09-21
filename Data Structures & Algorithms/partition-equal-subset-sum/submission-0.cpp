class Solution {
public:
    bool subsetSum(int id, int currSum, int target, vector<int> &nums){
        if (currSum == target) {
            return true;
        }
        if (id >= nums.size()){
            return false;
        }
        if (currSum > target) {
            return false;
        }
        return subsetSum(id + 1, currSum + nums[id], target, nums)
        || subsetSum(id + 1, currSum, target, nums);
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); ++i) {
            target += nums[i];
        }
        if (target % 2 == 1){
            return false;
        }
        return subsetSum(0, 0, target/2 , nums);
    }
};
