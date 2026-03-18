class Solution {
public:
    vector<vector<int>> dp;

    int solve(int a, int b, int m, int n) {
        if (a >= m || b >= n) return 0;

        if (a == m - 1 && b == n - 1) return 1;

        if (dp[a][b] != -1) return dp[a][b];

        int right = solve(a, b + 1, m, n);
        int down = solve(a + 1, b, m, n);

        return dp[a][b] = right + down;
    }

    int uniquePaths(int m, int n) {
        dp=vector<vector<int>>(m, vector<int>(n, -1));
        return solve(0, 0, m, n);
    }
};