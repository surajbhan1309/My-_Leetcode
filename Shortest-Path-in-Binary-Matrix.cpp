class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 || n==0 || grid[0][0]!=0){
            return -1;
        }
        int delrow[]={-1,-1,-1,0,0,1,1,1};
        int delcol[]={-1,0,1,-1,1,-1,0,1};

        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int steps=1;

        while(!q.empty()){
            int ns=q.size();
            while(ns--){
                auto curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;

                if(x==m-1 && y==n-1){
                    return steps;
                }
                for(int k=0;k<8;k++){
                    int nx=x+delrow[k];
                    int ny=y+delcol[k];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0){
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    } 
                }
            }
            steps++;
        }
        return -1;
        
    }
};