
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int profit=0;
                if(j){
                    int pick=-prices[i]+dp[i+1][0];
                    int notPick=0+dp[i+1][1];
                    profit=max(pick,notPick);
                }
                else{
                    int pick=prices[i]+dp[i+1][1];
                    int notPick=0+dp[i+1][0];
                    profit=max(pick,notPick);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];
    }
};
