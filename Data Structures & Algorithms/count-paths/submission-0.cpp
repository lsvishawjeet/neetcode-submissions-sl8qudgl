class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        // move right and bottom
        int total = 0;
        if(j+1 < n){
            total += dfs(i, j+1, m, n, dp);
        }
        if(i+1 < m){
            total += dfs(i+1, j, m, n, dp);
        }
        return dp[i][j] = total;
    }
    int uniquePaths(int m, int n) {
        /*
            simple prpblem:
            at rach [i][j] store the max i can reach, and use the dfs
            return number of possible unique paths
        */
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, dp);
    }
};
