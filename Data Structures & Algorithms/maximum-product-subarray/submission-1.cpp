class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // store Max Product at index i
        // if nums[i] is +ve 
        // maxProd = max(nums[i], nums[i] * maxProd[i-1])
        // if nums[i] is -ve 
        // maxProd = max(nums[i], nums[i] * minProd[i-1])
        // store Min Product at index i
        // if nums[i] is +ve 
        // minProd = max(nums[i], nums[i] * minProd[i-1])
        // if nums[i] is -ve 
        // maxProd = max(nums[i], nums[i] * maxProd[i-1])
        int n = nums.size(), maxRes = INT_MIN;
        vector<int> maxProd(n);
        vector<int> minProd(n);
        maxProd[0] = minProd[0] = nums[0];
        maxRes = nums[0];
        for (int i = 1; i < n; ++i) {
            
            maxProd[i] = max(nums[i], max(nums[i] * minProd[i-1], nums[i] * maxProd[i-1]));
            minProd[i] = min(nums[i], min(nums[i] * minProd[i-1], nums[i] * maxProd[i-1]));
            maxRes = max(maxRes, maxProd[i]);
        }
        return maxRes;
    }
};
