class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    bool dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& vis){
        if(r == 0 || c == board[0].size()-1 || r == board.size()-1 || c == 0){
            cout<<"got true for: "<<r<<" "<<c<<endl;
            return true;
        }
        vis[r][c] = true;
        for(auto direction : directions){
            int nr = direction[0]+r;
            int nc = direction[1]+c;
        
            if(nr >= 0 && nc>=0 && nr < board.size() && nc < board[0].size() && board[nr][nc] == 'O' && !vis[nr][nc]){
                if(dfs(board, nr, nc, vis)) return true;
            }
        }
        return false;
    }
    void solve(vector<vector<char>>& board) {
        // algorithn
        // a region is surrounded if it impossible to reach at border
        // we only travel through O's
        // if we reach border then its not
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> vis(rows, vector<bool>(cols, false));
                if (board[i][j] == 'O') {
                    bool border = dfs(board, i, j, vis);
                    if (!border) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};