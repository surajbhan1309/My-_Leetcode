class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1) return -1;

        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({0,0});
        vis[0][0]=1;
        int steps=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto[row,col]=q.front();
                q.pop();

                if(row==n-1 && col==m-1) return steps;

                for(int k=0;k<8;k++){
                    int nrow=row+dr[k];
                    int ncol=col+dc[k];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};