class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int find=original;
        for(auto &x:nums){
            if(x==find){
                find=2*x;
            }
        }
        return find;
        
    }
};