class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &word1,string &word2){
        if(i==word1.size() || j==word2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=1+solve(i+1,j+1,word1,word2);
        }
        else {
            return dp[i][j]=max(solve(i+1,j,word1,word2),solve(i,j+1,word1,word2));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,word1,word2);
        return n+m-2*ans;
    }
};