class Solution {
public:
    string shortestCommonSupersequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // DP table for LCS
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Fill DP (bottom-up)
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(word1[i] == word2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        // Build SCS directly
        string scs = "";
        int i = 0, j = 0;

        while(i < n && j < m){
            if(word1[i] == word2[j]){
                scs += word1[i];
                i++; j++;
            }
            else if(dp[i+1][j] > dp[i][j+1]){
                scs += word1[i];
                i++;
            }
            else{
                scs += word2[j];
                j++;
            }
        }

        // Add remaining characters
        while(i < n) scs += word1[i++];
        while(j < m) scs += word2[j++];

        return scs;
    }
};