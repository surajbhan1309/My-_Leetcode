class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startrow =0;
        int endrow =n-1;
        int endcol =n-1;
        int startcol =0;

        vector<vector<int>> ans(n, vector<int>(n,0));
        int i=1;

        while(i<=n*n && startrow<=endrow && startcol <= endcol){
            
            for(int j=startcol ; j<=endcol && i<=n*n ; j++){
                
                ans[startrow][j] = i;
                i++;
            }
            startrow++;
            for(int j=startrow ; j<=endrow && i<=n*n; j++){
                ans[j][endcol] = i;
                i++;
            }
            endcol--;
            for(int j=endcol ; j>=startcol && i<=n*n; j--){
                ans[endrow][j] = i;
                i++;
            }
            endrow--;
            for(int j=endrow ; j>=startrow && i<=n*n; j--){
                ans[j][startcol] = i;
                i++;
            }
            startcol++;
        }
        return ans;
    }
};