class Solution {
public:
    void findWord(int r, int c, int i, vector<vector<char>>& board, string word, bool & doesExist){
        // compare the rc with the word[i] if not eqal break
        if(i == word.size()){
            doesExist = true;
            return;
        }
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c] != word[i] || board[r][c] == '#' || doesExist){
            return;
        }
        char w = board[r][c];
        board[r][c] = '#';
        findWord(r+1, c, i+1, board, word, doesExist);
        findWord(r-1, c, i+1, board, word, doesExist);
        findWord(r, c+1, i+1, board, word, doesExist);
        findWord(r, c-1, i+1, board, word, doesExist);
        board[r][c] = w;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool doesExist = false;
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                findWord(i, j, 0, board, word, doesExist);
                if(doesExist){
                    return true;
                }
            }
        }
        return doesExist;
    }
};