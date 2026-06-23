// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int>minCoins(amount+1,amount+1);
//         minCoins[0]=0;

//         for(int i=1;i<=amount;i++){
//             for(int j=0;j<coins.size();j++){
//                 if(i>=coins[j]){
//                     minCoins[i]=min(minCoins[i],minCoins[i-coins[j]]+1);
//                 }
//             }
//         }
//         return minCoins[amount] > amount  ? -1 : minCoins[amount]; 
//     }
// };
class Solution {
private:
    int solve(int ind, int amount, const vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (ind == coins.size() || amount < 0) return 1e9;
        
        if (dp[ind][amount] != -1) return dp[ind][amount];

        int take = 1 + solve(ind, amount - coins[ind], coins, dp);
        int notTake = solve(ind + 1, amount, coins, dp);

        return dp[ind][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        int ans = solve(0, amount, coins, dp);
        
        return ans >= 1e9 ? -1 : ans;
    }
};