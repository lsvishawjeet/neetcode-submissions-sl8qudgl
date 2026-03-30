class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // use dijikstra algorithm
        /*
            take a priority queue, give priority to the distance
            insert the start node into priority queue
            take a distance array  and store the distance to it
        */
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto n : times){
            int u = n[0];
            int v = n[1];
            int cost = n[2];
            adj[u].push_back({v,cost});
        }
        pq.push({0,k}); // pushed the distance and starting node
        distance[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto nodes : adj[node]){
                // q shouldd continas the total cost till that node
                int newDis = nodes.second + dis;
                int newNode = nodes.first;
                if(newDis < distance[newNode]){
                    distance[newNode] = newDis;
                    pq.push({newDis, newNode});
                }
            }
        }
        int maxi = 0;
        for(int i=1; i<distance.size(); i++){
            if(distance[i] == INT_MAX) return -1;
            maxi = max(maxi, distance[i]);
        }
        return maxi;
    }
};
