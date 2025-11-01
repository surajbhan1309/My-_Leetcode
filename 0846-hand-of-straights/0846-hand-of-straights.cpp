class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>countM;
        for(auto &x:hand){
            countM[x]++;
        }
        for(auto it:countM){
            if(countM[it.first]>0){
                for(int i=1;i<groupSize;i++){
                    countM[it.first+i]-=countM[it.first];
                    if(countM[it.first+i]<0){
                        return false;
                    }
                }
            }
        }
        return true;

        
    }
};