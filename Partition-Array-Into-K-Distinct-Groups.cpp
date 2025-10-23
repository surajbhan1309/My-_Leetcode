class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int>hashM;
        for(auto &x:nums){
            hashM[x]++;
        }
        if(nums.size()%k!=0){
            return false;
        }
        int group=nums.size()/k;
        for(auto &x:hashM){
            if(x.second>group){
                return false;
            }              
            
        }
        return true;
    }
};