class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorans=0;
        for(auto &x:nums){
            xorans^=x;
        }
        if(xorans!=0) return nums.size();
        for(auto &x:nums){
            if(x!=0) return nums.size()-1;
        }
        return 0;
        
    }
};