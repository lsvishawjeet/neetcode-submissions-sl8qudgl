class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // this is dijikstra but with adding k stops to condition too
        // from to cost
        // algo for dijikstra :
        
        map<int, vector<pair<int,int>>> adj;

        for(auto flight : flights){
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            adj[from].push_back({to, cost});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // weight, from, count
        int sourceFlight = src;
        pq.push({0, src, 0});
        int cost = -1;
        
        while(!pq.empty()){
            int topCost = pq.top()[0];
            int topFlight = pq.top()[1];
            int visitedBefore = pq.top()[2]; // count how many are visited before
            pq.pop();
            if(visitedBefore <= k+1 && topFlight == dst){
                return topCost;
            }

            for(auto f : adj[topFlight]){
                int newCost = topCost + f.second;
                pq.push({newCost, f.first, visitedBefore+1});
            }
        }
        return cost;
    }
};
