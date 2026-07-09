class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &a,string &b){
        if(i==a.size() || j==b.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            dp[i][j]=1+solve(i+1,j+1,a,b);
        }
        else{
            dp[i][j]=max(solve(i,j+1,a,b),solve(i+1,j,a,b));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        string s2=s;
        reverse(s2.begin(),s2.end());
        return solve(0, 0, s, s2);    
    }
};