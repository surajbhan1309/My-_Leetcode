class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int prev_buy, prev_sell = 0;

        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, buy);

            prev_sell = sell;
            sell = max(prev_buy + price, sell);
        }
        return sell;
    }
};