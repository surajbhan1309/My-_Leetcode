class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row =matrix.size();
        int col =matrix[0].size();

        vector<pair<int,int>>v;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                }
            }
        }
        int I=-1,J=-1;

        for(auto it:v){
            if(!v.empty()){
                I=it.first;
                J=it.second;
            }
            if((I!=-1)&&(J!=-1)){
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