class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int val = INT_MAX;
        int n = nums.size();

        for (int i=0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                if (nums[i]!=0 && nums[j]!=0 && abs(nums[i]-nums[j]) >= 1) {
                    val = min(val, abs(i-j));
                }
            }
        }

        return (val==INT_MAX) ? -1:val;
    }
};