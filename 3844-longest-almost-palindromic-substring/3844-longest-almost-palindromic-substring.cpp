class Solution {
public:
    int solve(string &s, int l, int r, bool rightFirst) {
        int n = s.size();
        int cnt = 0;
        int temp = 1;

        while (cnt < 2 && l >= 0 && r < n) {
            if (s[l] == s[r]) {
                temp = max(temp, r - l + 1);
                l--;
                r++;
            } else {
                if (rightFirst) {
                    if (r + 1 < n && s[l] == s[r + 1]) {
                        cnt++;
                        r++;
                    } else if (l - 1 >= 0 && s[r] == s[l - 1]) {
                        cnt++;
                        l--;
                    } else break;
                } else {
                    if (l - 1 >= 0 && s[r] == s[l - 1]) {
                        cnt++;
                        l--;
                    } else if (r + 1 < n && s[l] == s[r + 1]) {
                        cnt++;
                        r++;
                    } else break;
                }
            }
        }

        if (cnt == 0 && temp < n) temp++;
        return temp;
    }

    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(s, i, i, true));
            ans = max(ans, solve(s, i, i, false));
            ans = max(ans, solve(s, i, i + 1, true));
            ans = max(ans, solve(s, i, i + 1, false));
        }

        return ans;
    }
};