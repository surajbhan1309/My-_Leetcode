class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if (i < 0 || j < 0) return 0;
        if (matrix[i][j] == 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        
        int up = solve(i - 1, j, matrix, memo);
        int left = solve(i, j - 1, matrix, memo);
        int diagonal = solve(i - 1, j - 1, matrix, memo);
        
        return memo[i][j] = min({up, left, diagonal}) + 1;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += solve(i, j, matrix, memo);
            }
        }
        return ans;
    }
};
