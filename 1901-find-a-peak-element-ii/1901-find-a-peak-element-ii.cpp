class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int max_row=0;
            for(int i=0;i<n;i++){
                if(matrix[i][mid]>matrix[max_row][mid]){
                    max_row=i;
                }
            }
                if((mid==0||matrix[max_row][mid]>matrix[max_row][mid-1]) &&
                    (mid==m-1 || matrix[max_row][mid]>matrix[max_row][mid+1])){
                        return {max_row,mid};
                    }
                else if(mid>0 && matrix[max_row][mid-1]>matrix[max_row][mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
        }
        return {-1,-1};
        
    }
};