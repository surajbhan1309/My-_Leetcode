class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};

        auto [mini_it, maxi_it] = minmax_element(nums.begin(), nums.end());
        int mini = *mini_it;
        int maxi = *maxi_it;

        unordered_set<int> num_set(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = mini + 1; i < maxi; i++) {
            if (num_set.find(i) == num_set.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
