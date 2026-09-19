class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        vector<int> res;
        int maxFreqSeen = 0;

        for (int i = 0; i < nums.size(); ++i) {
            freqMap[nums[i]]++;
            maxFreqSeen = max(maxFreqSeen, freqMap[nums[i]]);
        }

        vector<vector<int>> freqBucket(maxFreqSeen + 1);

        for (const auto& it: freqMap) {
            freqBucket[it.second].push_back(it.first);
        }
        
        for (int i = maxFreqSeen; i >= 0 && k > 0; --i) {
            for (int j = 0; j < freqBucket[i].size(); ++j) {
                res.push_back(freqBucket[i][j]);
                k--;
            }
        }
        return res;
    }
};
