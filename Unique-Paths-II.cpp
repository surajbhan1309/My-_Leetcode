class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePaths(m - 1, n - 1, obstacleGrid, dp);
    }
    int uniquePaths(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;
    if (grid[i][j] == 1) return 0;
    if (i == 0 && j == 0) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    int up = uniquePaths(i - 1, j, grid, dp);
    int left = uniquePaths(i, j - 1, grid, dp);

    return dp[i][j] = up + left;
}

    
};