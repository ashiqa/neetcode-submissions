/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto item : intervals){
            if (minHeap.empty() || minHeap.top() > item.start){
                minHeap.push({item.end});
            } else {
                minHeap.pop();
                minHeap.push({item.end});
            }
        }
        return minHeap.size();
    }
};
