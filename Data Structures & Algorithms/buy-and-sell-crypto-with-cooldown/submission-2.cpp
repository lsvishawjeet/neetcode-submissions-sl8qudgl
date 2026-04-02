class Solution {
public:
    int dfs(int i, int canBuy, vector<int>& prices, vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        int profit = 0;
        if(canBuy == 1){
            profit = max(dfs(i+1, 1, prices, dp),-prices[i] + dfs(i+1, 0, prices, dp));
        } else{
            profit = max(dfs(i+1, 0, prices, dp), prices[i] + dfs(i+2, 1, prices, dp));
        }
        return dp[i][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0,1,prices,dp);
    }
};
