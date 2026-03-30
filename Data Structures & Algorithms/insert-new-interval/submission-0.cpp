class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> sol;

        while(i<n && newInterval[0] > intervals[i][1]){
            sol.push_back(intervals[i]);
            i++;
        }
        // till this point we have all the valid intervals inserted
        // now insert the new interval
        while(i<n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        sol.push_back(newInterval);
        while(i<n){
            sol.push_back(intervals[i]);
            i++;
        }
        return sol;
    }
};
