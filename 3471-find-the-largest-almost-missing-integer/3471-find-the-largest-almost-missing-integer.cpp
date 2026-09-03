class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarray_counts;
        unordered_map<int, int> current_window;

        for (int i = 0; i < n; i++) {
            current_window[nums[i]]++;

            if (i >= k) {
                int left_elem = nums[i - k];
                current_window[left_elem]--;
                if (current_window[left_elem] == 0) {
                    current_window.erase(left_elem);
                }
            }

            if (i >= k - 1) {
                for (auto& pair : current_window) {
                    subarray_counts[pair.first]++;
                }
            }
        }

        int ans = -1;
        for (auto& pair : subarray_counts) {
            if (pair.second == 1) {
                ans = max(ans, pair.first);
            }
        }

        return ans;
    }
};