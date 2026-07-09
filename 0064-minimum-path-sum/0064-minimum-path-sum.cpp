class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m,n,dp,0,0,grid);
    }
    int solve(int m,int n,vector<vector<int>>&dp,int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n) return 1e9;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int down=solve(m,n,dp,i+1,j,grid);
        int right=solve(m,n,dp,i,j+1,grid);

        return dp[i][j]=grid[i][j]+min(down,right);
        
    }
};
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {

//         int m=grid.size();
//         int n=grid[0].size();

//         vector<vector<int>>dp(m,vector<int>(n,0));

//         dp[0][0]=grid[0][0];

//         for(int row=1;row<m;row++)
//         {
//             dp[row][0]=dp[row-1][0]+grid[row][0];
//         }

//         for(int col=1;col<n;col++)
//         {
//             dp[0][col]=dp[0][col-1]+grid[0][col];
//         }

//         for(int row=1;row<m;row++)
//         {
//             for(int col=1;col<n;col++)
//             {
//                 dp[row][col]=min(dp[row-1][col],dp[row][col-1])+grid[row][col];
//             }
//         }

//         return dp[m-1][n-1];

        
//     }
// };