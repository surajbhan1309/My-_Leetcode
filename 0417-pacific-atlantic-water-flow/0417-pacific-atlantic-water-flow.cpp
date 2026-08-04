class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>result;
        vector<vector<bool>>pacificVis(m,vector<bool>(n,false));
        vector<vector<bool>>atlanticVis(m,vector<bool>(n,false));

        for(int j=0;j<n;j++){
            dfs(heights,0,j,INT_MIN,pacificVis);//first row
            dfs(heights,m-1,j,INT_MIN,atlanticVis);//last row
        }
        for(int i=0;i<m;i++){
            dfs(heights,i,0,INT_MIN,pacificVis);//first col
            dfs(heights,i,n-1,INT_MIN,atlanticVis);//last col
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacificVis[i][j] && atlanticVis[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;

    }
    void dfs(vector<vector<int>>&heights,int i,int j,int prevcellval,vector<vector<bool>>&visited){
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size()){return;}
        if(heights[i][j]<prevcellval || visited[i][j]){return;}
        visited[i][j]=true;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];

            dfs(heights,nr,nc,heights[i][j],visited);
        }
    }
};