class Solution {
public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.length()-1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(string s, vector<vector<string>> &sol, vector<string> &currVec, int i){
        if(i >= s.length()){
            sol.push_back(currVec);
            return;
        }
        for(int j=i ; j<s.length(); j++){
            if(isPalindrome(s.substr(i,j-i+1))){
                currVec.push_back(s.substr(i,j-i+1));
                dfs(s, sol, currVec, j+1);
                currVec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol; vector<string> currVec;
        dfs(s, sol, currVec, 0);
        return sol;
    }
};
