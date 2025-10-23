class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int result1=INT_MAX;
        int result2=INT_MAX;
        int ans1=0;
        int ans2=0;
        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                if(landStartTime[i]+landDuration[i]>=waterStartTime[j]){
                    ans1=landStartTime[i]+landDuration[i]+waterDuration[j];
                }
                else{
                    ans1=waterStartTime[j]+waterDuration[j];
                }
                result1=min(ans1,result1);

            }
        }
        for(int j=0;j<waterStartTime.size();j++){
            for(int i=0;i<landStartTime.size();i++){
                if(waterStartTime[j]+waterDuration[j]>=landStartTime[i]){
                    ans2=waterStartTime[j]+waterDuration[j]+landDuration[i];
                }
                else{
                    ans2=landStartTime[i]+landDuration[i];
                }
                result2=min(ans2,result2);
            }
        }
        int result=min(result1,result2);
        return result;
        
    }
};