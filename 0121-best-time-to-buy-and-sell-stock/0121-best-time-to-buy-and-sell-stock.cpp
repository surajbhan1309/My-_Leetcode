class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buy=prices[0];
        for(auto &price:prices){
            if(price-buy>=0){
                profit=max(profit,price-buy);
            }
            else {
                buy=price;
            }
        }
        return profit;
        
    }
};