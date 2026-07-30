class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> points(mx+1,0);
        for(int x:nums){
            points[x]+=x;
        }
        vector<int> dp(mx+1);
        dp[0]=0;
        dp[1]=points[1];
        for(int i=2;i<=mx;i++){
            dp[i]=max(dp[i-1],points[i]+dp[i-2]);
        }
        return dp[mx];
    }
};

// class Solution {
// public:
//     int solve(vector<int>& nums,int i,vector<int>& dp){
//         if(i==nums.size())return 0;
//         if(dp[i]!=-1)return dp[i];

//         //take it
//         int upIdx=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
//         int nxtIdx=upper_bound(nums.begin(),nums.end(),nums[i]+1)-nums.begin();

//         int take=nums[i]*(upIdx-i)+solve(nums,nxtIdx,dp);
//         int leave=solve(nums,upIdx,dp);
//         return dp[i]=max(take,leave);
//     }
//     int deleteAndEarn(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<int>dp(nums.size(),-1);
//         return solve(nums,0,dp);

        
//     }
// };