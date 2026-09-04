class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Maximum subarray sum in circular array.

        // If max subarray sum in circular array then we will calculate the minimum sum of subarray and Subtract it from total_sum of array.

        int sum=0,curr_sum1=0,curr_sum2=0;
        int max_sub=INT_MIN;
        int min_sub=INT_MAX;

        for(auto &x:nums){
            sum+=x;
            curr_sum1+=x;
            curr_sum2+=x;
            max_sub=max(max_sub,curr_sum1);
            if(curr_sum1<0) curr_sum1=0;
            min_sub=min(min_sub,curr_sum2);
            if(curr_sum2>0) curr_sum2=0;
        }
        if(sum==min_sub) return max_sub;
        return max(max_sub,sum-min_sub);
    }
};