class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> lookUpTable;
        vector<int> sequenceStarts; 
        int res = 0;

        // cache in a map
        for (int item: nums) {
            lookUpTable.insert(item);
        }

        // start of sequences 
        for (int item: nums) {
            if(lookUpTable.find(item - 1) == lookUpTable.end()) {
                sequenceStarts.push_back(item);
            }
        }

        // find sequences
        for (int start : sequenceStarts) {
            int currLCS = 1;
            int currElem = start;
            while(lookUpTable.find(currElem + 1) != lookUpTable.end()) {
                currLCS += 1;
                currElem = currElem + 1;
            }
            res = max(res, currLCS);
        }
        return res;
    }
};
