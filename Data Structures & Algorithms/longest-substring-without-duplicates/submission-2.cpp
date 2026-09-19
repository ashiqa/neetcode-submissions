class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> elemPosHash;
        int startIndex = 0, currLen = 0, maxlen = 0;
        // map <element , position>
        // check if you element is duplicate
        // * check if it is within the current window (mp[elem] >= startIndex)
        // ** Yes - startIndex = pos + 1
        //        - len = i - startIndex + 1;
        for (int i = 0; startIndex <s.length() && i < s.length(); ++i) {
            if (elemPosHash.find(s[i]) == elemPosHash.end()){
                currLen++;
            } else {
                int pos = elemPosHash[s[i]];
                if (pos < startIndex){
                    currLen++;
                } else {
                    startIndex = elemPosHash[s[i]] + 1;
                    currLen = i - startIndex + 1;
                }
            }
            maxlen = max(maxlen, currLen);
            elemPosHash[s[i]] = i;
        }
        return maxlen;
    }
};
