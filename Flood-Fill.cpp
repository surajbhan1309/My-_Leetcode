class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalcolor=image[sr][sc];
        if(originalcolor==color) return image;
        int n=image.size();
        int m=image[0].size();
        dfs(sr,sc,n,m,image,originalcolor,color);
        return image;  
    }
    void dfs(int sr,int sc,int n,int m,vector<vector<int>>&image,int originalcolor,int color){
        if(sr<0|| sr>=n||sc<0||sc>=m||image[sr][sc]==color||image[sr][sc]!=originalcolor) return;
        image[sr][sc]=color;
        dfs(sr,sc-1,n,m,image,originalcolor,color);
        dfs(sr,sc+1,n,m,image,originalcolor,color);
        dfs(sr-1,sc,n,m,image,originalcolor,color);
        dfs(sr+1,sc,n,m,image,originalcolor,color);

    }
};