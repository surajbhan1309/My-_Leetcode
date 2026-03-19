class Solution {
public:
    int dp[201][20001];
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        int x=sum/2;
        return solve(0,x,nums);
    }
    bool solve(int i,int target,vector<int>&nums){
        if(target==0) return true;
        if(i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool take=false;
        if(nums[i]<=target){
            take=solve(i+1,target-nums[i],nums);
        }
        bool not_take=solve(i+1,target,nums);
        return dp[i][target]=take||not_take;

    }
};