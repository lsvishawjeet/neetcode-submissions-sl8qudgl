class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& vis , bool& top, bool& left, bool& bottom, bool& right){
        if(vis[r][c]) return;
        if((top || left) && (bottom || right)) return;
        vis[r][c] = true;
        if(r == 0) top = true;
        if(c == 0) left = true;
        if(r == heights.size() - 1) bottom = true;
        if(c == heights[0].size() - 1) right = true;
        for(auto direction : directions){
            int nr = r + direction[0];
            int nc = c + direction[1];
            if(nr >= 0 && nc>=0 && nr < heights.size() && nc < heights[0].size()){
                if(heights[nr][nc] <= heights[r][c]){
                    dfs(heights, nr, nc, vis, top, left, bottom, right);
                }
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // do dfs at each node
        // while doing dfs, if you reach at both : top||left && bottom||right then push it to vector
        vector<vector<int>> sol;
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[i].size(); j++){
                vector<vector<bool>> vis(heights.size(), vector<bool>(heights[0].size(), false));
                bool top = false;
                bool left= false;
                bool bottom= false;
                bool right = false;
                dfs(heights, i, j, vis, top, left, bottom, right);
                if((top||left) && (bottom||right)){
                    sol.push_back({i,j});
                }
            }
        }
        return sol;
    }
};
