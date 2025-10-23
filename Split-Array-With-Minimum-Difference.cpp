class Solution {
public:
    long long splitArray(vector<int>& nums) {
       long long ans=LLONG_MAX;
       vector<long long>rightsum(nums.size());
       int prev=-1;
       long long sum=0;
       for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>prev){
                sum+=nums[i];
                rightsum[i]=sum;
                prev=nums[i];
            }
            else break;
       }
       prev=-1,sum=0;
       for(int i=0;i+1<nums.size();i++){
        if(nums[i]>prev){
            sum+=nums[i];
            if(rightsum[i+1]!=0){
                ans=min(ans,abs(sum-rightsum[i+1]));
            }
            prev=nums[i];
        }
        else break;
       }
       return ans==LLONG_MAX?-1:ans;
        
    }
};