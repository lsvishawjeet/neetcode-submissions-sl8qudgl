class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq; // stores distance and index

        for(int i = 0; i<points.size(); i++){
            int point1 = points[i][0];
            int point2 = points[i][1];
            double dis = sqrt((point1 * point1) + (point2 * point2));
            pq.push({dis, i});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>> sol;
        while(!pq.empty()){
            sol.push_back(points[pq.top().second]);
            pq.pop();
        }

        return sol;

    }
};
