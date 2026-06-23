class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // CHANGED: Use 'unsigned int' instead of 'int' to prevent overflow crashes
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(amount + 1, 0)); 
        
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i-1] <= j) {
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        // The final return automatically casts back to the required 'int'
        return dp[n][amount]; 
    }
};

// class Solution {
// public:
//     int dp[301][5001];
//     int n;
//     int solve(int i,vector<int> &coins,int amount){
//         if(dp[i][amount]!=-1) return dp[i][amount];
//         if(amount==0) return 1;
//         if(i==n || amount<0) return 0;

//         if(coins[i]>amount){
//             return dp[i][amount]=solve(i+1,coins,amount);
//         }
//         int take=solve(i,coins,amount-coins[i]);
//         int nottake=solve(i+1,coins,amount);

//         return dp[i][amount]=take+nottake;
//     }
//     int change(int amount, vector<int>& coins) {
//         n=coins.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(0,coins,amount);
//     }
// };