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
        if (n == 1) return nums[0];   // only one house
        if (n == 2) return max(nums[0], nums[1]); // two houses

        // Case 1: Exclude last house
        vector<int> case1(nums.begin(), nums.end() - 1);
        vector<int> dp1(case1.size(), -1);
        int ans1 = maxMoneyMem(dp1, case1, 0);

        // Case 2: Exclude first house
        vector<int> case2(nums.begin() + 1, nums.end());
        vector<int> dp2(case2.size(), -1);
        int ans2 = maxMoneyMem(dp2, case2, 0);

        return max(ans1, ans2);
    }
};
