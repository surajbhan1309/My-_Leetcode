class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=LLONG_MIN;
        long long range=1e5;

        long long n3=1LL*nums[n-1]*nums[n-2]*range;
        long long n4=1LL*nums[0]*nums[1]*range;
        long long n5=1LL*nums[0]*nums[n-1]*(-range);

        return max({n3,n4,n5});
    }
};