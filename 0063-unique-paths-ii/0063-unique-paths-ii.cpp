class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, -1));

        return solve(0, 0, obstacleGrid, dp);
    }

    long long solve(int i, int j, vector<vector<int>> &grid, vector<vector<long long>> &dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n) return 0;     // out of bounds
        if (grid[i][j] == 1) return 0;      // obstacle
        if (i == m - 1 && j == n - 1) return 1;  // destination

        if (dp[i][j] != -1) return dp[i][j];

        long long down = solve(i + 1, j, grid, dp);
        long long right = solve(i, j + 1, grid, dp);

        return dp[i][j] = down + right;
    }
};