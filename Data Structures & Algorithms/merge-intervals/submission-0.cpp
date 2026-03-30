class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> st;
        int i = 0;
        int n = intervals.size();
        st.push(intervals[0]);
        if(n < 2) return intervals;
        while(i < n){
            auto interval1 = st.top();
            auto interval2 = intervals[i];
            // compare these
            if(interval1[1] >= interval2[0]){
                st.pop();
                interval1[0] = (min(interval1[0], interval2[0]));
                interval1[1] = (max(interval1[1], interval2[1]));
                st.push(interval1);
            } else{
                st.push(interval2);
            }
            i++;
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
