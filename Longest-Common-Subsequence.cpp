class Solution {
public:
    int dp[1001][1001]; // memoization table

    int solve(int i, int j, string &a, string &b) {
        if (i == a.size() || j == b.size()) return 0; // base case
        if (dp[i][j] != -1) return dp[i][j]; // return cached result

        if (a[i] == b[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, a, b);
        } else {
            return dp[i][j] = max(solve(i + 1, j, a, b), solve(i, j + 1, a, b));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp)); // initialize memo table
        return solve(0, 0, text1, text2);
    }
};
