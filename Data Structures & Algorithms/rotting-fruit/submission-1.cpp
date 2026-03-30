class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        // algorithm:
        // push all the rotten orangges to the queue for BFS
        queue<pair<int, int>> q;
        int min = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty()){
            int size = q.size();
            bool isChanged = false;
            for(int i=0; i<size; i++){
                auto orange = q.front();
                int r = orange.first;
                int c = orange.second;
                q.pop();
                for(auto direction:directions){
                    int nr = direction[0] + r;
                    int nc = direction[1] + c;
                    if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1){
                        isChanged = true;
                       grid[nr][nc] = 2;
                       q.push({nr,nc});
                   }
                }
            }
            if(isChanged) min++;
        }
        // check if any fresh fruit left
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return min;
    }
};
