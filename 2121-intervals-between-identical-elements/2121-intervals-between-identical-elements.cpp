class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ans(n, 0);

        unordered_map<int, long long> sum, cnt;

        // Left → Right
        for (int i = 0; i < n; i++) {
            long long f = cnt[arr[i]];
            long long s = sum[arr[i]];

            ans[i] += f * i - s;

            cnt[arr[i]]++;
            sum[arr[i]] += i;
        }

        // Reset
        sum.clear();
        cnt.clear();

        // Right → Left
        for (int i = n - 1; i >= 0; i--) {
            long long f = cnt[arr[i]];
            long long s = sum[arr[i]];

            ans[i] += s - f * i;

            cnt[arr[i]]++;
            sum[arr[i]] += i;
        }

        return ans;
    }
};