class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<0) return 0;
        vector<int>minDP(amount+1,INT_MAX);
        minDP[0]=0;
        for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(i-coin>=0 && minDP[i-coin]!=INT_MAX){
                    minDP[i]=min(minDP[i],minDP[i-coin]+1);
                }
            }
        }
        return (minDP[amount]==INT_MAX)?-1:minDP[amount];
        
    }
};