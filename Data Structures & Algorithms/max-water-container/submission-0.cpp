class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, res = 0;
        while (l < r) {
            int len = min(heights[l], heights[r]);
            int b = r - l;
            res = max(res, len * b);
            if (len == heights[l])l++;
            else r--;
        }
        return res;
    }
};
