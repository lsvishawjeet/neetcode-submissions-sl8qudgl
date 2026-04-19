class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /*
            use greedy approach here
        */
        // first sosrt on the basis on end time
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        int count = 1;
        int lastIntervalIndex = 0;
        for(int i =0 ; i < intervals.size(); i++){
            if(intervals[lastIntervalIndex][1] <= intervals[i][0]){
                count++;
                lastIntervalIndex = i;
            }
        }
        return intervals.size()-count;

    }
};