class Solution {
private:
    bool isValid(vector<string> & board, int row, int col){
        int c = col;
        for(int i = row-1; i>=0; i--){
            if(board[i][col] != '.') return false;
            c--;
            int dif = col - c;
            if(c>=0 && board[i][c] != '.') return false;
            if(col+dif<board.size() && board[i][col+dif] != '.') return false;
        }
        return true;
    }
    void placeQueens(vector<string>& board, vector<vector<string>>& sol, int i, int n){
        if(i>=n){
            sol.push_back(board);
            return;
        }
        for(int j = 0; j<n; j++){
            if(isValid(board, i, j)){
                board[i][j] = 'Q';
                placeQueens(board, sol, i+1, n);
            } else{
                continue;
            }
            board[i][j] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> chessBoard(n, string(n,'.'));
        placeQueens(chessBoard, sol, 0, n);
        return sol;
    }

};
