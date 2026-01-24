class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);

        int i = 1, k = 0;

        while (i < n) {
            if (s[i] == s[k]) {
                k++;
                lps[i] = k;
                i++;
            } else {
                if (k > 0) {
                    k = lps[k - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return s.substr(0, lps[n - 1]);
    }
};
