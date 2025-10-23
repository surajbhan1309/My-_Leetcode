

class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int target) {
        // Out-of-bound target
        if (target < -1000 || target > 1000) return 0;

        // Base case
        if (i == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        // If already calculated
        if (dp[i][target + 1000] != -1) {
            return dp[i][target + 1000];
        }

        // Add and subtract current number
        int plus = solve(nums, i + 1, target - nums[i]);
        int minus = solve(nums, i + 1, target + nums[i]);

        return dp[i][target + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // DP size: [n][2001] to handle target from -1000 to +1000
        dp.resize(n, vector<int>(2001, -1));
        return solve(nums, 0, target);
    }
};


