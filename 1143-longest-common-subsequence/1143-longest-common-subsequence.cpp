class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &text1,string &text2){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==text1.size() || j==text2.size()) return 0;

        if(text1[i]==text2[j]){
            dp[i][j]=solve(i+1,j+1,text1,text2)+1;
        }
        else{
            dp[i][j]=max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));
        }
        return dp[i][j];

    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,text1,text2);
    }
};