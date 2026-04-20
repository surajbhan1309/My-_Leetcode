class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=1;
        int high=nums[n-1];
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(Issumpossible(mid,nums,threshold)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
    bool Issumpossible(int mid,vector<int>& nums,int threshold){
        int sum=0;
        for(auto &x:nums){
            sum+=(x+mid-1)/mid;
        }
        return sum<=threshold;
    }
};