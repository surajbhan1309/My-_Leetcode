class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        memset(dp,-1,sizeof(dp));
        int LCSlen=LCSlength(word1,word2,0,0);
        return n+m-2*LCSlen;
    }
    int LCSlength(string &a,string &b,int i,int j){
        if(i==a.size() || j==b.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            dp[i][j]=LCSlength(a,b,i+1,j+1)+1;
        }
        else{
            dp[i][j]=max(LCSlength(a,b,i+1,j),LCSlength(a,b,i,j+1));
        }
        return dp[i][j];
    }
};