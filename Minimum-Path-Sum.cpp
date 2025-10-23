class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return minpath(0,0,grid,dp,m,n);
    }
    int minpath(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int m,int n){
        if(i<0||i>=m||j<0||j>=n){
            return 1e9;
        }
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=minpath(i,j+1,grid,dp,m,n);
        int down=minpath(i+1,j,grid,dp,m,n);
        return dp[i][j]=grid[i][j]+min(right,down);
    }
};