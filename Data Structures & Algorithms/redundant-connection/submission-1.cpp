class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // create adj array
        // use topo sort
        vector<vector<int>> adj(edges.size()+1);
        vector<int> indegree(edges.size()+1, 0);
        queue<int> q;
        // insert to adj
        for(auto el : edges){
            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(el[0]);
            indegree[el[0]]++;
            indegree[el[1]]++;
        }
        // now traverse throught adj and push to q
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==1) q.push(i);
        }
        // 
        while(!q.empty()){
            int top = q.front(); q.pop();
            // go throught parallel elements
            for(auto nei : adj[top]){
                // reduce the indegree
                indegree[nei]--;
                if(indegree[nei] == 1){
                    q.push(nei);
                }
            }
        }
        // now traverse backwar of edges
        // if there is element whose indegree >= 2 then that is redundant
        for(int i= edges.size()-1; i>=0; i--){
            int v = edges[i][0];
            int u = edges[i][1];
            if(indegree[u] >= 2 && indegree[v]>=2){
                return {v,u};
            }
        }
        return {};
    }
};
