class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(dp,s,0,n);
    }
    int solve(vector<int>&dp,string &s,int i,int n){
        if(dp[i]!=-1) return dp[i];
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        dp[i]=solve(dp,s,i+1,n);
        if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                dp[i]+=solve(dp,s,i+2,n);
            }
        }
        return dp[i];
    }
};