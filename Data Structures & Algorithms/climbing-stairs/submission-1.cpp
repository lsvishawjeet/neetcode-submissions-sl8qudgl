class Solution {
private:
    int climb(int n, int i, vector<int>& dp){
        if(n == i) return 1;
        if(i > n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = climb(n, i+1, dp) + climb(n, i+2, dp);
    }
public:
    int climbStairs(int n) {
       vector<int> dp(n+1,-1); // this will store the number of count at current step
       return climb(n, 0, dp);
    }
};
