class Solution {
public:
    bool dfs(unordered_map<string, vector<string>> &adj, unordered_map<string, vector<bool>> &adj_vis, vector<vector<string>> &sols, vector<string>& curr, int n){
        // adj -> adjacency list
        // adj_vis -> visited array of what we visited
        // sols -> this contains solutions
        // curr -> this si currenct solution
        // n -> this is no of nodes in solution required

        // push condition
        if(curr.size() == n){
            sols.push_back(curr);
            return true;
        }
        int i = curr.size()-1;
        if(adj[curr[i]].size() < 1){
            return false;
        }
        string currentTicket = curr[i];
        // pick and not pick
        for(int m = 0; m<adj[currentTicket].size(); m++){
            if(adj_vis[currentTicket][m]) continue;
            adj_vis[currentTicket][m] = true;
            vector<string> curr1 = curr;
            curr1.push_back(adj[currentTicket][m]);
            if(dfs(adj, adj_vis, sols, curr1, n)) return true;
            adj_vis[currentTicket][m] = false;
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /*
            Its not a basic traversal problem
            your goal is to travel the path that is valid ie cover all the locations but lexicography is priority
            so here backtracking will sove the problem (maybe)
            find all the valid paths and store them
            then find the lexicographical best path and retunr tha
        */
        unordered_map<string, vector<string>> adj; 
        unordered_map<string, vector<bool>> adj_vis; // to track record of if visited or not
        
        int n = 1 + tickets.size();
        for(auto ticket: tickets){
            adj[ticket[0]].push_back(ticket[1]);
            adj_vis[ticket[0]].push_back(false);
        }
        for(auto &a : adj){
            sort(a.second.begin(), a.second.end());
        }
        vector<vector<string>> sol;
        vector<string> curr = {"JFK"};
        dfs(adj, adj_vis, sol, curr, n);
        // now find the best lexicographical solution
        cout<<sol.size()<<endl;
        vector<string> ans = sol[0];

        return ans;
    }
};

