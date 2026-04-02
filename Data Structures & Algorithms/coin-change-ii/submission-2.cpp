class Solution {
public:
    int dfs(int i, int amount, vector<int>& coins, int currTotal, vector<vector<int>> &dp){
        if(i > coins.size()-1 || currTotal > amount){
            return 0;
        }
        if(currTotal == amount){
            return 1;
        }
        if(dp[i][currTotal] != -1) return dp[i][currTotal];
        // take ele and dont move forwad + move forward and take el + move forward but dont take el
        int total = dfs(i, amount, coins, currTotal+coins[i], dp) + 
                    dfs(i+1, amount, coins, currTotal, dp);

        return dp[i][currTotal] = total;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        return dfs(0, amount, coins, 0, dp);
    }
};
