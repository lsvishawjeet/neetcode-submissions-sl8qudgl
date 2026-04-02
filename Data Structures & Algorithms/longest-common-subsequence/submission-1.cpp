class Solution {
public:
    int dfs(int i, int j, string text1, string text2, vector<vector<int>> &dp){
        // return consdiotn:
        if(i==text1.length() || j==text2.length()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i]==text2[j]) {
            return 1+dfs( i+1,  j+1,  text1,  text2, dp);
        } 
        return dp[i][j] = max(dfs(i+1, j, text1, text2, dp), dfs(i, j+1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        /*
             Think recursiverly first
             we have two strings
             conpare the text1[i] and text2[j], if equal, move next and add 1 to result
             if not equal then try two possibilities, move i only and move j only
        */
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return dfs(0,0,text1, text2, dp);
    }
};
