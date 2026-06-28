class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        int time=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dRow[]={-1,1,0,0};
        int dCol[]={0,0,-1,1};

        while(!q.empty() && fresh>0){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int row=r+dRow[d];
                    int col=c+dCol[d];

                    if(row<0 || row>=rows || col<0 || col>=cols || grid[row][col]!=1){
                        continue;
                    }
                    grid[row][col]=2;
                    q.push({row,col});
                    fresh--;
                }
            }
            time++;
        }
        return fresh==0 ? time : -1;
        
    }
};