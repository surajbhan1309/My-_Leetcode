class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;

        for(int x : nums) sum += x;

        long long mul = 1;

        for(long long i = n - 1; i >= 0; i--) {
            sum -= nums[i];

            if(sum == mul) return i;

            mul *= nums[i];

            if(mul > sum) return -1;
        }

        return -1;
    }
};