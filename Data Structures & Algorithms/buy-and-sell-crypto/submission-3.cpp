class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // using two pointer (sliding window)

        int l = 0;
        int r = 1;
        int profit = 0;

        while(r<prices.size()){
            int buyPrice = prices[l];
            int sellPrice = prices[r];
            if(buyPrice < sellPrice){
                profit = max(profit, sellPrice-buyPrice);
            } else{
                // as we fount the smaller buy price, so we will buy this day
                l = r;
            }
            r++;
        }

        return profit;

    }
};
