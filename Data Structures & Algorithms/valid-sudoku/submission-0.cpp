class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for(int i=0; i<9; i++){
            map<char, int> mp;
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    mp[board[i][j]]++;
                    if(mp[board[i][j]]>1) return false;
                }
            }
        }
        // check columns
        for(int i=0; i<9; i++){
            map<char, int> mp;
            for(int j=0; j<9; j++){
                if(board[j][i] != '.'){
                    mp[board[j][i]]++;
                    if(mp[board[j][i]]>1) return false;
                }
            }
        }

        // check 3x3 grid at each level
        for(int r=0; r<9; r+=3){
            for(int c=0; c<9; c+=3){
                map<char, int> mp;;
                for(int j=0; j<3; j++){
                    for(int k=0; k<3; k++){
                        if(board[r+j][c+k] != '.'){
                            mp[board[r+j][c+k]]++;
                            if(mp[board[r+j][c+k]]>1) return false;
                        }
                    }
                }
            }
            
        }
        return true;
    }
};
