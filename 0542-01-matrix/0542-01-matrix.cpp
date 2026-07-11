class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            auto[row,col,steps]=q.front();
            q.pop();
            dist[row][col]=steps;
            for(int k=0;k<4;k++){
                int nrow=row+dr[k];
                int ncol=col+dc[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol,steps+1});
                }
            }
        }
        return dist;
    }
};