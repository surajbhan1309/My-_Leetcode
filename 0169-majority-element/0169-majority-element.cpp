class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     // sort(nums.begin(),nums.end());
    //     // int n=nums.size();
    //     // return nums[n/2];
    // }
    //Moore voting algo 
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int element = nums[0];
        int n = nums.size();

        // Find candidate
        for (int i = 1; i < n; i++) {
            if (nums[i] == element)
                count++;
            else if (count == 0) {
                element = nums[i];
                count = 1;
            } else {
                count--;
            }
        }

        // Verification step
        count = 0;
        for (int x : nums) {
            if (x == element)
                count++;
        }

        if (count > n / 2)
            return element;

        return -1; // No majority element exists
    }
};