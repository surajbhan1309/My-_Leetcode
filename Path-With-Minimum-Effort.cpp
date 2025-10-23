class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));

        priority_queue<p,vector<p>,greater<p>>pq;
        result[0][0]=0;
        pq.push({0,{0,0}});


        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        

        while(!pq.empty()){
            int diff=pq.top().first;
            auto coord=pq.top().second;
            pq.pop();

            int x=coord.first;
            int y=coord.second;

            for(int k=0;k<4;k++){
                int nx=x+delrow[k];
                int ny=y+delcol[k];

                if(nx<m && nx>=0 && ny<n && ny>=0){
                    int absdiff=abs(heights[x][y]-heights[nx][ny]);
                    int maxdiff=max(diff,absdiff);

                    if(result[nx][ny]>maxdiff){
                        result[nx][ny]=maxdiff;
                        pq.push({maxdiff,{nx,ny}});
                    }
                }
            }
        }
        return result[m-1][n-1];

        
    }
};