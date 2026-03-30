class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int node, int parent){
        if(vis[node]){
            return true;
        }
        vis[node] = true;
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i] == parent) continue;
            if(dfs(adj, vis, adj[node][i], node)){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // how to detect cycle
        // mark the node that is visited
        // if the parent node is same as this node
        // for example:
        /* 
        0->1
        1->0
        here we travel from 0 to 1, so ndoe is 1 and parent in 0, we pass (1,0)
        and market it as visited
        noe the node is 0 and parent is 1, but the node==parent which we will skip
        if its visited but the parent node is diff then return true

        0 -> 1
        0 -> 2
        0 -> 3
        1 -> 4

        */
        vector<vector<int>> adj(n);
        for(auto node : edges){
            adj[node[0]].push_back(node[1]);
            adj[node[1]].push_back(node[0]);
        }
        vector<bool> vis(n, false);
        // check if all visited
        bool cycleDetected = dfs(adj, vis, 0, -1);
        for(auto e : vis){
            if(!e) return false;
        }
        return !cycleDetected;
    }
};
