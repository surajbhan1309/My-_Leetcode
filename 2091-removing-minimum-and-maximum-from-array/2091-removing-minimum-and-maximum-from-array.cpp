class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(min_idx, max_idx);
        int right = max(min_idx, max_idx);

        int del_left = right + 1;
        int del_right = n - left;
        int del_both = (left + 1) + (n - right);

        return min({del_left, del_right, del_both});
    }
};
