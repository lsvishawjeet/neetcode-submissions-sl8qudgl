class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
            first sort the intervals
            check end and start of the interval. Eg
            [1,3], [1,5], [6,7]
            3 > 1
            so overlap, merge these. ie:
                put [1, 5] in new array and move j
                now check 
        */
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> sol;
        sol.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++){
            // check the intervals[i] and sol[j]
            int s = sol.size()-1;
            int newLow = intervals[i][0];
            int newHigh = intervals[i][1];
            int prevHigh = sol[s][1];
            if(newLow <= prevHigh){
                sol[s][1] = max(prevHigh, newHigh);
            } else {
                sol.push_back({newLow, newHigh});
            }
        }
        return sol;
    }
};
