class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        long long i = lower;
        int idx = 0;
        int n = nums.size();

        while (i <= upper) {
            while (idx < n && nums[idx] < i) {
                idx++;
            }

            if (idx < n && nums[idx] == i) {
                i++;
                continue;
            }

            long long start = i;
            while (i <= upper && (idx >= n || nums[idx] > i)) {
                i++;
            }
            long long end = i - 1;

            ans.push_back({(int)start, (int)end});
        }

        return ans;
    }
};
