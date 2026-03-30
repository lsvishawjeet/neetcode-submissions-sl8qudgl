class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean){
        // this function visit each possible cell and mark that index true for passed index
        if(ocean[r][c]) return;
        ocean[r][c] = true;
        for(auto direction : directions){
            int nr = direction[0] + r;
            int nc = direction[1] + c;
            if(nr >=0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && heights[nr][nc]>=heights[r][c]){
                dfs(heights, nr, nc, ocean);
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // start dfs for each border node
        // create a new vector of same size of heights
        // it contains which border element reached this
        // return the boxes which contains both
        
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> sol;
        vector<vector<bool>> pacificVisit(row, vector<bool>(col, false));
        vector<vector<bool>> atlanticVisit(row, vector<bool>(col, false));
        // top row
        for(int i=0; i<col; i++){
            dfs(heights, 0, i, pacificVisit);
        }
        // left cols
        for(int i=0; i<row; i++){
            dfs(heights, i, 0, pacificVisit);
        }
        // bottom row
        for(int i=0; i<col; i++){
            dfs(heights, row-1, i, atlanticVisit);
        }
        // right col
        for(int i=0; i<row; i++){
            dfs(heights, i, col-1, atlanticVisit);
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(atlanticVisit[i][j] && pacificVisit[i][j]){
                    sol.push_back({i,j});
                }
            }
        }
        return sol;
    }
};
