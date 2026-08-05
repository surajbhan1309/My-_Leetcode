class Solution {
public:
    int count;
    int countSubstrings(string s) {
        count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            check(i,i,s,n);
            check(i,i+1,s,n);
        }
        return count;
    }
    void check(int i,int j,string &s,int n){
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
    }
};

// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n=s.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(ispal(dp,s,i,j)){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
//     int ispal(vector<vector<int>>&dp,string &s,int i,int j){
//         if(i==j) return 1;
//         if(j==i+1 && s[i]==s[j]) return 1;
//         if(dp[i][j]!=-1) return dp[i][j];
//         dp[i][j]=((s[i]==s[j]) && ispal(dp,s,i+1,j-1));
//         return dp[i][j];
//     }
// };
