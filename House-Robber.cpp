class Solution {
public:
    int maxMoneyMem(vector<int>& dp, vector<int>& houses, int index) {
        if (index >= houses.size()) return 0;
        
        if (dp[index] != -1) return dp[index];

        int include = houses[index] + maxMoneyMem(dp, houses, index + 2);
        int exclude = maxMoneyMem(dp, houses, index + 1);

        dp[index] = max(include, exclude);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxMoneyMem(dp, nums, 0);
    }
};
