class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n + 1), right(n + 1);

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                    cnt++;
                }
            }
            left[cnt].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i + n];
                    cnt++;
                }
            }
            right[cnt].push_back(sum);
        }

        // Sort right subsets for binary search
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // Try all valid combinations
        for (int k = 0; k <= n; k++) {
            for (int s1 : left[k]) {
                int need = (total / 2) - s1;
                auto& vec = right[n - k];
                auto it = lower_bound(vec.begin(), vec.end(), need);

                if (it != vec.end()) {//this only gives sum>=need
                    int s2 = *it;
                    ans = min(ans, abs(total - 2 * (s1 + s2)));
                }

                if (it != vec.begin()) { //by this sum>need by taking removing previous
                    --it;
                    int s2 = *it;
                    ans = min(ans, abs(total - 2 * (s1 + s2)));
                }
            }
        }
        return ans;
    }
};
