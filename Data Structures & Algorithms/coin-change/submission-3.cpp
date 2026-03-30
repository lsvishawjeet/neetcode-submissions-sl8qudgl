class Solution {
public:
    int countCoins(vector<int>& coins, int amount, unordered_map<int,int>& dp){
        if(amount == 0) return 0;
        if(dp.find(amount) != dp.end()) return dp[amount];
        int res = 1e9;
        for(auto coin : coins){
            if(amount >= coin){
                res = min(res, 1+countCoins(coins, amount-coin, dp));
            }
        }
        return dp[amount] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int , int> dp;
        int sol = countCoins(coins, amount, dp);
        return sol == 1e9 ? -1 : sol;
    }
};