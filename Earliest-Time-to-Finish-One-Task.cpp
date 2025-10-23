
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini=INT_MAX;
        int rows=tasks.size();
        int cols=tasks[0].size();
        for(int i=0;i<rows;i++){
            int sum=0;
            for(int j=0;j<cols;j++){
                sum+=tasks[i][j];
            }
            mini=min(mini,sum);
        }
        return mini;
        
    }
};