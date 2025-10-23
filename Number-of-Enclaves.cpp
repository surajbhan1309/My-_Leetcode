class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        //First row and last row
        for(int j=0;j<n;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid,m,n,delrow,delcol);
            }
            if(!vis[m-1][j] && grid[m-1][j]==1){
                dfs(m-1,j,vis,grid,m,n,delrow,delcol);
            }
        }
        //First and last column
        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid,m,n,delrow,delcol);
            }
            if(!vis[i][n-1] && grid[i][n-1]==1){
                dfs(i,n-1,vis,grid,m,n,delrow,delcol);
            }
        }
        
        long long count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
        
    }
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int m,int n,int delrow[],int delcol[]){
        vis[row][col]=1;
        for(int k=0;k<4;k++){
            int nrow=row+delrow[k];
            int ncol=col+delcol[k];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
             !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,m,n,delrow,delcol);
            }
        }
    }
};