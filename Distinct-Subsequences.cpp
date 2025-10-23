class Solution {
public:
    int dp[1001][1001];
    int dfs(int i,int j,const string&s,const string&t){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            dp[i][j]=dfs(i+1,j+1,s,t) + dfs(i+1,j,s,t);
        }
        else{
            dp[i][j]=dfs(i+1,j,s,t);
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,s,t);
    }
};