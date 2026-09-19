class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            freqMap[nums[i]]++;
        }
        for (const auto& it: freqMap) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
