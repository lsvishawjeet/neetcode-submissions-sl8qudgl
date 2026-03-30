class Solution {
public:
    void findWord(int i, int j, string s, vector<vector<char>>& board, string word, bool & doesExist, vector<vector<bool>>& isVisited){
        if(s == word || doesExist){
            doesExist = true;
            return;
        }
        if(i >= board.size() || j >= board[0].size() || i<0 || j<0 || isVisited[i][j]){
            return;
        }
        isVisited[i][j] = true;
        // move in all directions (dont repeat the word)
        findWord(i+1, j, s + board[i][j], board, word, doesExist, isVisited);
        findWord(i-1, j, s + board[i][j], board, word, doesExist, isVisited);
        findWord(i, j+1, s + board[i][j], board, word, doesExist, isVisited);
        findWord(i, j-1, s + board[i][j], board, word, doesExist, isVisited);
        isVisited[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool doesExist = false;
        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                findWord(i,j,"", board, word, doesExist, isVisited);
                if(doesExist){
                    return true;
                }
            }
        }
        return doesExist;
    }
};