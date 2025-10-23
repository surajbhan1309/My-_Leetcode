class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int val=nums[0];
        for(auto &x:nums){
            if(x!=nums[0]){
                return 1;
            }
        }
        return 0;   
    }
};