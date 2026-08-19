class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX;
        int maxProfit = 0;
        for(int n:prices){
            maxProfit = max(maxProfit, n-minBuy);
            minBuy = min(minBuy, n);
        }
        return maxProfit;
    }
};
