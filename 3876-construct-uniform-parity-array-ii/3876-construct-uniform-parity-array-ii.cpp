class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=nums1[0];
        bool haveodds=false;

        for(auto &x:nums1){
            if(x<mini){
                mini=x;
            }
            if(x&1==1){
                haveodds=true;
            }
        }

        return (mini&1==1)||!haveodds;
        
    }
};