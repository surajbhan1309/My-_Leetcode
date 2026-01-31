class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int maxVal = 0;
            int best = 0;

            for (int j = i; j < n && j < i + k; j++) {
                maxVal = max(maxVal, arr[j]);
                best = max(best, maxVal * (j - i + 1) + dp[j + 1]);
            }
            dp[i] = best;
        }

        return dp[0];
    }
};
