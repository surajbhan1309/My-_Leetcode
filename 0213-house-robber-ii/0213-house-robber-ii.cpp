class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Case 1: Exclude the last house
        vector<int> case1(nums.begin(), nums.end() - 1);
        vector<int> dp1(case1.size(), -1);
        int ans1 = solve(case1, 0, dp1);

        // Case 2: Exclude the first house
        vector<int> case2(nums.begin() + 1, nums.end());
        vector<int> dp2(case2.size(), -1);
        int ans2 = solve(case2, 0, dp2);

        return max(ans1, ans2);
    }

    int solve(vector<int>& houses, int i, vector<int>& dp) {
        if (i >= houses.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int include = houses[i] + solve(houses, i + 2, dp);
        int exclude = solve(houses, i + 1, dp);

        return dp[i] = max(include, exclude);
    }
};
