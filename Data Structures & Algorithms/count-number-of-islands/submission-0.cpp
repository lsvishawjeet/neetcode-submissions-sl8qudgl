class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';
        // traverse left, right, bottom, top
        if(r-1 >= 0) dfs(grid, r-1, c);
        if(r+1 < grid.size()) dfs(grid, r+1, c);
        if(c-1 >= 0) dfs(grid, r, c-1);
        if(c+1 < grid[0].size()) dfs(grid, r, c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        // approach:
        // start dfs
        // connect the nodes whose adjacent are one
        // take visited array and mark true when going
        // skip and break if its 0
        // continue
        // now greate a graph like this: grid[0][0] -> grid[0][1], grid[1][0]
        // now traverse throught the generated graph and do dfs and increment count with 1 when end is reached
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;

    }
};
