class Solution {
public:
    int dp[103][103];
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        memset(dp,-1,sizeof(dp));
        return solve(cuts,0,cuts.size()-1);
    }
    int solve(vector<int>&cuts,int left,int right){
        if((right-left)==1) return 0;
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int result=INT_MAX;
        for(int index=left+1;index<=right-1;index++){
            int cost=solve(cuts,left,index)+solve(cuts,index,right)+cuts[right]-cuts[left];
            result=min(result,cost);
        }
        return dp[left][right]=result;
    }

};