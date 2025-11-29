class Solution {
public:
    int solve(vector<int>&dp,vector<int>&nums,int i,int n){
        if(i==n-1){
            return true;
        }
        if(nums[i]==-0){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int reach=i+nums[i];
        for(int jump=i+1;jump<=reach;jump++){
            if(jump<nums.size() && solve(dp,nums,jump,n)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(dp,nums,0,n);      
    }
};