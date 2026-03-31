class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // this is problem of prims algorithm
        // create the priority queue which stores the weight and the node

        int size = points.size();
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {weight, node}

        // creeate vis array
        vector<bool> vis(size, false);

        pq.push({0, 0});

        int visEdges = 0;
        int sol = 0;

        while(visEdges < size){
            int topWeight = pq.top().first;
            int topNode = pq.top().second;
            pq.pop();
            if(vis[topNode]) continue;
            sol+=topWeight;
            vis[topNode] = true;
            visEdges++;
            for(int i=0; i<size; i++){
                if(vis[i]) continue;
                int newWeight = abs(abs(points[i][0] - points[topNode][0]) + abs(points[i][1] - points[topNode][1]));
                pq.push({newWeight, i});
            }
        }
        return sol;

    }
};
