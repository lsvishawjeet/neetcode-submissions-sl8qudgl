class Solution {
public:
    vector<pair<int, int>> directions = {
        {0, -1}, //left
        {1, 0}, //bottom
        {0, 1}, // right
        {-1, 0} // top
    };
    int swimInWater(vector<vector<int>>& grid) {
        /*
            // lets first do this with dfs and backtracking
            // do it with dijikstra / greedy algo, at each step pick the smallest
        */
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;
        int sol = INT_MAX;
        while(!pq.empty()){
            int currWeight = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            if(i == grid.size()-1 && j == grid[0].size()-1){
                return currWeight;
            }
            // travel in all directions
            for(auto direction : directions){
                int newI = direction.first + i;
                int newJ = direction.second + j;
                if(newI >= 0 && newJ >= 0 && newI < grid.size() && newJ < grid[0].size() && !vis[newI][newJ]){
                    vis[newI][newJ] = true;
                    pq.push({max(grid[newI][newJ], currWeight), newI, newJ});
                }
            }
        }
        return sol;
        
    }
};
