class Solution {
public:
    int getXSum(vector<int>& nums, int start, int end, int x) {
        unordered_map<int, int> freq;
        for (int i = start; i < end; i++) freq[nums[i]]++;

        vector<pair<int, int>> count(freq.begin(), freq.end());
        sort(count.begin(), count.end(), [](auto &a, auto &b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        });

        int sum = 0;
        for (int i = 0; i < x && i < count.size(); i++)
            sum += count[i].first * count[i].second;

        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i + k <= n; i++)
            ans.push_back(getXSum(nums, i, i + k, x));
        return ans;
    }
};