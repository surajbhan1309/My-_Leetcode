class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        int ops = 0;

        while(j < n){
            if(nums[i] >= nums[j]){
                int diff = nums[i] + 1 - nums[j];
                ops += diff;
                nums[j] += diff;
            }
            i++;
            j++;
        }

        return ops;
    }
};