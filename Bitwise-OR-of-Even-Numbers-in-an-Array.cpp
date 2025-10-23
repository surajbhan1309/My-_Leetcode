class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int bitnum=0;
        for(auto &x:nums){
            if(x&1) continue;
            else{
                bitnum|=x;
            }
        }
        return bitnum;
        
    }
};