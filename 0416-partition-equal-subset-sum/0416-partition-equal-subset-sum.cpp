class Solution {
public:
    int dp[201][20001];
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        int half=sum/2;
        return solve(half,nums,0);
    }
    bool solve(int target,vector<int>&nums,int i){
        if(target==0) return true;
        if(i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool take=false;
        if(nums[i]<=target){
            take=solve(target-nums[i],nums,i+1);
        }
        bool not_take=solve(target,nums,i+1);
        return dp[i][target]=take || not_take;
    }
};