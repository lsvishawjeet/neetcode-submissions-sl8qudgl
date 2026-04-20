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
        /*
            detect total numbenr of conflicts
        */
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        // pq.push(intervals[0].end);
        for(int i = 0 ; i<intervals.size(); i++){
            if(!pq.empty()){
                int prevEnd = pq.top();
                int currStart = intervals[i].start;
                if(prevEnd <= currStart){
                    pq.pop();
                }
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
        
    }
};
