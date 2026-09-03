class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> total_counts;
        for (int x : nums) {
            total_counts[x]++;
        }

        if (k == 1) {
            int ans = -1;
            for (auto& pair : total_counts) {
                if (pair.second == 1) {
                    ans = max(ans, pair.first);
                }
            }
            return ans;
        }

        if (k == n) {
            int ans = -1;
            for (auto& pair : total_counts) {
                ans = max(ans, pair.first);
            }
            return ans;
        }

        int first = nums[0];
        int last = nums[n - 1];
        int ans = -1;

        if (total_counts[first] == 1) {
            ans = max(ans, first);
        }
        if (total_counts[last] == 1) {
            ans = max(ans, last);
        }

        return ans;
    }
};