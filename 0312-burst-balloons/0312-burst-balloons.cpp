class Solution {
public:
    int dp[303][303];
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,nums.size()-1);
    }
    int solve(vector<int>&nums,int left,int right){
        if(left+1>=right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int result=-1;
        for(int index=left+1;index<=right-1;index++){
            int cost=solve(nums,left,index)+solve(nums,index,right)+nums[left]*nums[index]*nums[right];
            result=max(result,cost);
        }
        return dp[left][right]=result;
    }

};