class Solution {
public:
    void par(string str, int open, int close, int n, vector<string>& ans) {
        if (str.length() == 2 * n) {
            ans.push_back(str);
            return;
        }
        if (open < n) {
            par(str + "(", open + 1, close, n, ans);
        }
        if (close < open) {
            par(str + ")", open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        par("", 0, 0, n, ans);
        return ans;
    }
};
