class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(partitions(mid,nums,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    bool partitions(int mid,vector<int>&nums,int k){
        int count=1;
        int sum=0;
        for(auto x:nums){
            if(x+sum<=mid){
                sum+=x;
            }
            else{
                count++;
                sum=x;
            }
        }
        return count<=k;
    }
};