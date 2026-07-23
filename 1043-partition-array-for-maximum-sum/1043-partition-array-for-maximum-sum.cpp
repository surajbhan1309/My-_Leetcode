class Solution {
public:
    int n;
    int dp[501];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,k);
    }
    int solve(vector<int>&arr,int i,int k){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int result=0;
        int maxval=-1;
        for(int j=i;j<n && j-i+1<=k;j++){
            maxval=max(maxval,arr[j]);
            result=max(result,maxval*(j-i+1)+solve(arr,j+1,k));
        }
        return dp[i]=result;
    }
};