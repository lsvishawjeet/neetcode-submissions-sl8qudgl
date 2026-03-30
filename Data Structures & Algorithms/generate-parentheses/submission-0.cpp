class Solution {
public:
    void generatePare(int openCount, int closeCount, int n, vector<string> &sol, string &curr){
        
        if(openCount == closeCount && openCount == n){
            sol.push_back(curr);
            return;
        }
        
        if(openCount < n){
            curr += '(';
            generatePare(openCount+1, closeCount, n, sol, curr);
            curr.pop_back();
        }
        if(closeCount < openCount){
            curr += ')';
            generatePare(openCount, closeCount+1, n, sol, curr);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string curr;
        generatePare(0, 0, n, sol, curr);
        return sol;
    }
};
