class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini=*min_element(nums.begin(),nums.end());
        long long maxi=*max_element(nums.begin(),nums.end());
        long long diff=maxi-mini;
        long long ans=diff*k;
        return ans;
        
    }
};