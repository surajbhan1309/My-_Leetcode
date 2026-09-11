class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int k = n / 2;
        long long total_sum = 0;
        
        for (int x : nums) {
            total_sum += x;
        }
        
        long long current_sum = 0;
        
        for (int i = 0; i < k; ++i) {
            current_sum += nums[i];
        }
        
        int good_rotations = 0;
        
        if (current_sum * 2 > total_sum) {
            good_rotations++;
        }
        
        for (int i = 1; i < n; ++i) {
            current_sum = current_sum - nums[i - 1] + nums[(i + k - 1) % n];
            
            if (current_sum * 2 > total_sum) {
                good_rotations++;
            }
        }
        
        return good_rotations;
    }
};