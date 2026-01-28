class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        // 1️⃣ Add boundaries
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // 2️⃣ Length-based DP (same as Matrix Chain)
        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;

                // 3️⃣ Try every partition (last cut)
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                        dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]));
                }
            }
        }

        return dp[0][m - 1];
    }
};
