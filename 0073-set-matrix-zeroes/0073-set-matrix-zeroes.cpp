class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<pair<int,int>>pos;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    pos.push_back({i,j});
                }
            }
        }
        int I=-1,J=-1;
        for(auto &x:pos){
            if(!pos.empty()){
                I=x.first;
                J=x.second;
            }
            if((I!=-1) && (J!=-1)){
                for(int j=0;j<col;j++){
                    matrix[I][j]=0;
                }
                for(int i=0;i<row;i++){
                    matrix[i][J]=0;
                }
            }
        }        
    }
};