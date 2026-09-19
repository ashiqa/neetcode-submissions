class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n = temperatures.size();
        vector<int> res (n, 0);
        for (int i = 0; i < n; ++i) {
            if (s.empty() or s.top().first >= temperatures[i]){
                s.push({temperatures[i], i});
            } else {
                while (s.size() > 0 && s.top().first < temperatures[i]) {
                    res[s.top().second] = i - s.top().second;
                    s.pop();
                }
                s.push({temperatures[i], i});
            }
        }
        return res;
    }
};
