class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp = grid;

    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col < n; col++) {
            int down = dp[row + 1][col];
            int downLeft = (col > 0) ? dp[row + 1][col - 1] : 1e9;
            int downRight = (col < n - 1) ? dp[row + 1][col + 1] : 1e9;
            dp[row][col] += min({down, downLeft, downRight});
        }
    }

    return *min_element(dp[0].begin(), dp[0].end());
}

};
