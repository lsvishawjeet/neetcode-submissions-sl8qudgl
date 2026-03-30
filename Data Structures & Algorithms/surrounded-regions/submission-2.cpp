class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    void dfs(vector<vector<char>>& board, int r, int c){
        if(board[r][c] != 'O') return;
        board[r][c] = '#';
        // travel in all four direction
        for(auto direction : directions){
            int nr = direction[0]+r;
            int nc = direction[1]+c;
            if(nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() && board[nr][nc]=='O'){
                dfs(board, nr, nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        // algorithn
        // first we figure out which 'O' is connected to border
        // only dfs those and better change them to some other alphabat
        // later traverse the whole board
        // if cell is equal to new alphabat then replace it with 'O', else with 'X'
        int rows = board.size();
        int cols = board[0].size();
        // traverse top row
        for(int i=0; i<cols; i++){
            dfs(board, 0, i);
        }
        // traverse bottom row
        for(int i=0; i<cols; i++){
            dfs(board, rows-1, i);
        }
        // traverse left
        for(int j=0; j<rows; j++){
            dfs(board, j, 0);
        }
        // traverse right
        for(int j=0; j<rows; j++){
            dfs(board, j, cols-1);
        }

        // now mark all '#' to 'O' and 'O' to 'X'
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};