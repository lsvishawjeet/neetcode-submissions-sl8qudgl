class Solution {
public:
    int INF = 2147483647;
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q){
        // algotirhm
        // here we are doing it level wise
        // we will return the level when we got the zero
        // this level is the minimum level as bfs goes level wise
        while(!q.empty()){
            auto topEl = q.front();
            int r = topEl.first;
            int c = topEl.second;
            q.pop();
            // move in all directions
            if(r-1 >=0 && grid[r-1][c] == INF){
                grid[r-1][c] = 1+grid[r][c];
                q.push({r-1, c});
            }
            if(r+1 < grid.size() && grid[r+1][c] == INF){
                grid[r+1][c] = 1+grid[r][c];
                q.push({r+1, c});
            }
            if(c-1 >=0 && grid[r][c-1] == INF) {
                grid[r][c-1] = 1+grid[r][c];
                q.push({r, c-1});
            }
            if(c+1 < grid[0].size() && grid[r][c+1] == INF){
                grid[r][c+1] = 1+grid[r][c];
                q.push({r, c+1});
            }
        }
        return INF;
        
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // find travel from INF to 0
        queue<pair<int,int>> q; // store {r and c}
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        bfs(grid, q);
    }
};
