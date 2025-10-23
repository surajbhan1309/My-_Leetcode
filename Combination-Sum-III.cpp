class Solution {
public:
    void subset(vector<int>& nums, int k, int target, vector<int>& path,
                vector<vector<int>>& result, int i, int sum) {
        if (path.size() == k && sum == target) {
            result.push_back(path);
            return;
        }
        if (sum > target || path.size() > k || i >= nums.size()) return;

        path.push_back(nums[i]);
        subset(nums, k, target, path, result, i + 1, sum + nums[i]);
        path.pop_back();

        subset(nums, k, target, path, result, i + 1, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> path;
        vector<vector<int>> result;
        subset(nums, k, n, path, result, 0, 0);
        return result;
    }
};
