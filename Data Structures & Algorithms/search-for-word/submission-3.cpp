class Solution {
public:
    vector<vector<int>> dir = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    bool found(vector<vector<char>>& board, int i, int j, string &word, string curr, int c, vector<vector<int>> &vis){
        //travel in all four directions
        if(c == word.size()) return true;
        for(auto &d : dir){
            int newRow = i+d[0];
            int newCol = j+d[1];
            if(newRow >= 0 && newCol >=0 && newRow < board.size() && newCol < board[0].size() && board[newRow][newCol] == word[c] && !vis[newRow][newCol]){
                vis[newRow][newCol] = 1;
                if(found(board, newRow, newCol, word, curr, c+1, vis)) return true;
                vis[newRow][newCol] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> vis(board.size(), vector<int>(board[0].size(),0));
                    vis[i][j] = 1;
                    if(found(board, i, j, word, "", 1, vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
