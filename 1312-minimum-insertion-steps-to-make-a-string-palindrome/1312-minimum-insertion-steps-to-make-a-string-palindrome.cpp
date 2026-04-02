class Solution {
public:
    int dp[501][501];
    int minInsertions(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        string s1=s;
        reverse(s1.begin(),s1.end());
        int LCSlen=LCSlength(s,s1,0,0);
        return n-LCSlen;
    }
    int LCSlength(string &s,string &s1,int i,int j){
        if(i==s.size() || j==s1.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s1[j]){
            dp[i][j]=LCSlength(s,s1,i+1,j+1)+1;
        }
        else{
            dp[i][j]=max(LCSlength(s,s1,i+1,j),LCSlength(s,s1,i,j+1));
        }
        return dp[i][j];
    }
};