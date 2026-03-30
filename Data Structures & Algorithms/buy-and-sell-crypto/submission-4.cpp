class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // using two pointer (sliding window)

        int minBuy = prices[0];
        int profit = 0;

        for(auto &price : prices){
            minBuy = min(price, minBuy);
            profit = max(profit, price-minBuy);
        }

        return profit;

    }
};
