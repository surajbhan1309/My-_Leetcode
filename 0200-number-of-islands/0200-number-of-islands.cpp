class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j,int n,int m){
        vis[i][j]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                dfs(grid,vis,nrow,ncol,n,m);
            }
        }
        
    }
};
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty() || grid[0].empty()) return 0;
        
//         int n = grid.size();
//         int m = grid[0].size();
//         int count = 0;
        
//         int dr[] = {-1, 0, 1, 0};
//         int dc[] = {0, 1, 0, -1};
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == '1') {
//                     count++;
                    
//                     queue<pair<int, int>> q;
//                     q.push({i, j});
//                     grid[i][j] = '0';
                    
//                     while (!q.empty()) {
//                         auto [r, c] = q.front();
//                         q.pop();
                        
//                         for (int k = 0; k < 4; k++) {
//                             int nrow = r + dr[k];
//                             int ncol = c + dc[k];
                            
//                             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1') {
//                                 q.push({nrow, ncol});
//                                 grid[nrow][ncol] = '0';
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };
