class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int n=prices.size();
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            else if(prices[i]-buy>profit){
                profit=prices[i]-buy;
            }
        }
        return profit;
    }
};