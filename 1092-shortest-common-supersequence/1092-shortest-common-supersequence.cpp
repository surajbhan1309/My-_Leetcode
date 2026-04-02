class Solution {
public:
    int dp[501][501];

    string shortestCommonSupersequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(dp, -1, sizeof(dp));

        // fill dp using recursion
        LCSlength(word1, word2, 0, 0);

        // build LCS string
        string lcs = buildLCS(word1, word2);

        // build SCS using LCS
        string scs = "";
        int i = 0, j = 0;

        for(char c : lcs){
            while(word1[i] != c) scs += word1[i++];
            while(word2[j] != c) scs += word2[j++];
            scs += c;
            i++; j++;
        }

        scs += word1.substr(i);
        scs += word2.substr(j);

        return scs;
    }

    int LCSlength(string &a, string &b, int i, int j){
        if(i == a.size() || j == b.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j]){
            return dp[i][j] = 1 + LCSlength(a, b, i+1, j+1);
        }
        else{
            return dp[i][j] = max(
                LCSlength(a, b, i+1, j),
                LCSlength(a, b, i, j+1)
            );
        }
    }

    // 🔥 Separate function to BUILD LCS string
    string buildLCS(string &a, string &b){
        string lcs = "";
        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                lcs += a[i];
                i++; j++;
            }
            else{
                // move based on dp
                if(dp[i+1][j] > dp[i][j+1]) i++;
                else j++;
            }
        }

        return lcs;
    }
};