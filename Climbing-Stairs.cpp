class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        
        // Create an array to store results of subproblems
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        
        // Fill the array in a bottom-up manner
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        // The final answer will be in dp[n]
        return dp[n];
    }
};
