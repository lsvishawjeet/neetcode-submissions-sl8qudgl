class Solution {
public:
    bool detectCycle(vector<vector<int>>& adj, vector<bool>& vis, int node, int parent){
        if(vis[node]) return true;
        vis[node] = true;

        for(auto n : adj[node]){
            if(n == parent) continue;
            if(detectCycle(adj, vis, n, node)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // create adj array
        // insert each node pair to array and then check if it creates cycle or not
        // if cycle is formed then return this pair
        vector<vector<int>> adj(edges.size()+1);
        
        for(auto e : edges){
            vector<bool> vis(edges.size()+1, false);
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            if(detectCycle(adj, vis, e[0], -1)){
                return {e[0], e[1]};
            }
        }
        return {};
    }
};
