class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node, int parent){
        if(vis[node]) return;
        vis[node] = true;
        for(auto n : adj[node]){
            if(n == parent){
                continue;
            }
            dfs(adj, vis, n, node);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // create adj list
        // then run for each node
        // if its not visited then increase count and visit all the connected nodes
        /*
        0 -> 1
        0 -> 2
        2 -> 3
        2 -> 4
        */

        vector<vector<int>> adj(n);
        for(auto node : edges){
            adj[node[0]].push_back(node[1]);
            adj[node[1]].push_back(node[0]);
        }
        vector<bool> vis(n, false);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i, -1);
                count++;
            }
        }
        return count;
    }
};
