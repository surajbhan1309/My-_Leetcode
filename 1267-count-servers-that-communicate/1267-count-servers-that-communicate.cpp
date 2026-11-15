class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>rowCOunt(m,0);
        vector<int>colCOunt(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowCOunt[i]++;
                    colCOunt[j]++;
                }
            }
        }
        int servers=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(rowCOunt[i]>1 || colCOunt[j]>1){
                        servers++;
                    }
                }
            }
        }
        return servers;
    }
};